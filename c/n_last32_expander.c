
// ResCounter = 430_281  MaxPointer = 267_107  Time in ms = 4843 
unsigned char last32[32] = {
0x72,0x73,0x09,0x5e,0x6d,0x09,0xf0,0x69,0x92,0x14,0x35,0xbb,0x20,0x60,0xe5,0x4d,0xb1,0xab,0xf1,0x13,0xab,0xc8,0x69,0x0a,0x05,0x51,0x32,0xdc,0xc8,0x6e,0x1c,0x4e,
};

// // ResCounter = 227_880  MaxPointer = 137_318  Time in ms = 1656
// unsigned char last32[32] = {
// 0xb9,0xf0,0x5e,0x7c,0xe1,0xa8,0x9c,0xef,0x30,0xff,0xcc,0x41,0xe1,0x16,0x69,0x0a,0x72,0x4a,0xda,0xfd,0xf1,0x13,0xed,0x89,0xc5,0x7e,0x58,0x4c,0xa3,0x5c,0x82,0x58,
// };

// // ResCounter = 181_062  MaxPointer = 132_420  Time in ms = 2468
// unsigned char last32[32] = {
// 0x7f,0x6f,0xca,0x87,0x5f,0x17,0x4c,0x5d,0x58,0x3e,0xc7,0x09,0x7f,0x1f,0xa5,0x63,0x00,0x85,0x00,0x85,0x00,0x85,0x00,0x85,0x00,0x85,0x00,0x85,0x00,0x85,0x00,0xc8,
// };

#define WRITE_2FILE			1
#define WRITE_2FILE_SHOWC	1

#define SAVE_RESULTS_EVERYN	50000
#define RESULTFILENAME		"__n_res_c_last32_expander.bin"

#define CHECKLISTMAXPOINTER	300000

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "n_data.inc"
#include "n_misc.inc"


clock_t tic;
u64 MaxPointer = 0;
u64 ResCounter = 0;


int WriteConsoleStatus() {
	clock_t toc = clock();
	printf("// ResCounter = ");
	printbigdec(ResCounter);
	printf("  MaxPointer = ");
	printbigdec(MaxPointer);
	printf("  Time in ms = %.f", (double)(toc - tic) * 1000 / CLOCKS_PER_SEC);
	printf("\n");
	return 1;
}


int main(int argc, char* argv[]) {
	struct checkblock* checklist = malloc(CHECKLISTMAXPOINTER * sizeof(struct checkblock));

	time_t t;
	struct tm tm;

	u8 temp32[32], i, a;
	u16 cx;
	u64 checklistpointer, ResMemCounter = 0;

	#if WRITE_2FILE == 1
		struct resblock* results = malloc(SAVE_RESULTS_EVERYN * sizeof(struct resblock));
		FILE *outfile;
		outfile = fopen(RESULTFILENAME, "wb");
	#endif

	checklistpointer = 1;

	memcpy(checklist[checklistpointer].check32, last32, 32);

	checklist[checklistpointer].iterations = 256;

	while (checklistpointer > 0) {
		if (MaxPointer < checklistpointer)
			MaxPointer = checklistpointer;

		u16 iterations_left = checklist[checklistpointer].iterations;

		if (iterations_left == 0)
		{
			ResCounter++;
			#if WRITE_2FILE == 1
				memcpy(results[ResMemCounter].result32, checklist[checklistpointer].check32, 32);
				ResMemCounter++;
				if (ResMemCounter == SAVE_RESULTS_EVERYN)
				{
					if (!(fwrite(results, ResMemCounter * sizeof(struct resblock), 1, outfile))) {
						printf("ERROR fwrite\n");
						fclose(outfile);
						free(results);
						free(checklist);
						return 0;
					}
					ResMemCounter = 0;
					#if WRITE_2FILE_SHOWC == 1
						WriteConsoleStatus();
					#endif
					#if EXIT_AFTER_NPLUSRES > 0
						if (ResCounter >= EXIT_AFTER_NPLUSRES)
							break;
					#endif
				}
			#endif
			checklistpointer--;
			continue;
		}

		memcpy(temp32, checklist[checklistpointer].check32, 32);

		#include "n_xor.inc"

		u8 rev2cnt=0;
		for (i = 0; i < 32; i++) {
			if (rev2[ checklist[checklistpointer].check32[i] ] > 0)
				rev2cnt++;
		}

		u64 addcnt = 1 << rev2cnt;

		if ((checklistpointer + addcnt) >= CHECKLISTMAXPOINTER)
		{
			printf("ERROR: checklistpointer >= CHECKLISTMAXPOINTER\n");
			#if WRITE_2FILE == 1
				fwrite(results, ResMemCounter * sizeof(struct resblock), 1, outfile);
				fclose(outfile);
				free(results);
			#endif
			free(checklist);
			return 0;
		}

		u64 periodval = 1;
		u64 periodcnt = periodval;
		for (i = 0; i < 32; i++)
		{
			a = checklist[checklistpointer].check32[i];
			u8 r2flag = 0;
			if (rev2[a] == 0) {
				for (u64 n = 0; n < addcnt; n++)
					checklist[checklistpointer+n].check32[i] = rev1[a];
			} else {
				for (u64 n = 0; n < addcnt; n++)	{
					if (r2flag == 0)
						checklist[checklistpointer+n].check32[i] = rev1[a];
					else
						checklist[checklistpointer+n].check32[i] = rev2[a];
					periodcnt--;
					if (periodcnt == 0) {
						r2flag = 1 - r2flag;
						periodcnt = periodval;
					}
				}
				periodval = periodval * 2;
			}
		}

		for (u64 n = 0; n < addcnt; n++)
			checklist[checklistpointer+n].iterations = iterations_left - 1;
		checklistpointer += addcnt - 1;
	}

	printf("\nFINAL:\n");

	WriteConsoleStatus();

	#if WRITE_2FILE == 1
		if (ResMemCounter > 0) {
			fwrite(results, ResMemCounter * sizeof(struct resblock), 1, outfile);
		}
		fclose(outfile);
		free(results);
	#endif
	free(checklist);
	
	return 1;
}

