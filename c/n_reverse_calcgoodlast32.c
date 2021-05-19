// v1.2 made by Zorro; zorropride gmail

// #define EXIT_AFTER_NPLUSRES	1
// #define WRITE_2FILE			1
// #define WRITE_2FILE_SHOWC	1

// one million benchmark
#define EXIT_AFTER_NPLUSRES	1000000
#define WRITE_2FILE			0
#define WRITE_2FILE_SHOWC	0

#define START_TRY_LO64		0
#define START_TRY_HI64		0

#define SAVE_RESULTS_EVERYN	50000
#define RESULTFILENAME		"__n_res_c.bin"

#define DEBUG_CONSOLE_LOG	0
#define CHECKLISTMAXPOINTER	900000

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "n_data.inc"
#include "n_misc.inc"


clock_t tic;
u64 MaxPointer = 0;
u64 ResCounter = 0;

u64 PrevResCnt = 0;
u64 GoodLast32 = 0;


int WriteConsoleStatus() {
	clock_t toc = clock();
	printf("Time in ms = %.f", (double)(toc - tic) * 1000 / CLOCKS_PER_SEC);
	printf("\tResCounter = ");
	printbigdec(ResCounter);
	printf("\tMaxPointer = ");
	printbigdec(MaxPointer);
	printf("\n");
	return 1;
}


int main(int argc, char* argv[]) {
	#if EXIT_AFTER_NPLUSRES < 1
		printf("ERROR: EXIT_AFTER_NPLUSRES < 1\n");
		return 0;
	#endif

	printf(" _____\n|[___]|\n|+ c +|\n`-----'\nreverse\n\n");

	printf("EXIT_AFTER_NPLUSRES = ");
	printbigdec(EXIT_AFTER_NPLUSRES);
	printf("\n");

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

	uint128 TryCounter, tx;
	TryCounter = START_TRY_HI64;
	TryCounter = TryCounter << 64;
	TryCounter += START_TRY_LO64;
	printf("start TryCounter = 0x");
	printbighex(TryCounter);
	printf("\n");

	clock_t tic = clock();

	while (1) {
		#if DEBUG_CONSOLE_LOG == 1
			printf("TryCounter 0x%016llx%016llx ",  (u64)(TryCounter >> 64), (u64)TryCounter);
			printf("ResCounter 0x%016llx\n", (u64)ResCounter);
			printf("last32byte ");
		#endif

		checklistpointer = 1;
		tx = TryCounter;
		for (i = 0; i < 16; i++)
		{
			cx = tx & 0xff;
			tx = tx >> 8;
			a = goodpairs[i*256*2+cx*2];
			checklist[checklistpointer].check32[i*2] = a;
			#if DEBUG_CONSOLE_LOG == 1
				printf("%02x", a);
			#endif
			a = goodpairs[i*256*2+cx*2+1];
			checklist[checklistpointer].check32[i*2+1] = a;
			#if DEBUG_CONSOLE_LOG == 1
				printf("%02x ", a);
			#endif
		}
		checklist[checklistpointer].iterations = 256;

		#if DEBUG_CONSOLE_LOG == 1
			printf("\n");
		#endif

		TryCounter++;
		PrevResCnt = 0;

		while (checklistpointer > 0) {
			if (MaxPointer < checklistpointer)
				MaxPointer = checklistpointer;

			u16 iterations_left = checklist[checklistpointer].iterations;

			if (iterations_left == 0)
			{
				ResCounter++;
				PrevResCnt++;
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

		if (PrevResCnt > 0) {
			GoodLast32++;
		}

		#if EXIT_AFTER_NPLUSRES > 0
			if (ResCounter >= EXIT_AFTER_NPLUSRES)
				break;
		#endif
	}

	printf("\nFINAL:\n");

	WriteConsoleStatus();

	printf("GoodLast32 = %llu\n", GoodLast32);

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
