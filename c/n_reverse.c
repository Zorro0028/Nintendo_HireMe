// made by Zorro; zorropride gmail
// v1.1; true 128bit counter to check all possible 256^16 combinations
#define EXITAFTER_NPLUSRES	1
#define TRYTEXTOUTPUT		1
#define WRITE_RESULTS2FILE	1
// // // one million results benchmark
// #define EXITAFTER_NPLUSRES	1000000
// #define TRYTEXTOUTPUT		0
// #define WRITE_RESULTS2FILE	1

#define SAVE_RESULTS_EVERYN	100000
#define RESULTFILENAME		"__n_res_c.bin"

#define CHECKLISTMAXPOINTER	200000

typedef unsigned char		u8;
typedef unsigned long long	u64;
typedef unsigned short int	u16;
typedef unsigned __int128	uint128;

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "n_data.inc"


struct checkblock {
	u8	check32[32];
	u16	iterations;
};


struct resblock {
	u8	result32[32];
};


int printbigdec(uint128 tx) {
	u8 bigdec[64], dx;
	u8 dnum = 0;
	u8 sepval = 0;
	while (tx > 0) {
		if (sepval == 3) {
			bigdec[64-dnum-1] = 111;
			sepval = 0;
			dnum++;
		}
		dx = tx % 10;
		tx = tx / 10;
		bigdec[64-dnum-1] = dx;
		dnum++;
		sepval++;
	}
	for (dx = 0; dx < dnum; dx++)
	{
		if (bigdec[64-dnum+dx] == 111)
			printf("_");
		else
			printf("%c", bigdec[64-dnum+dx]+'0');
	}
	return 0;
}


int main(int argc, char* argv[])
{
	printf(" _____\n|[___]|\n|+ c +|\n`-----'\nloading\n\n");

	struct checkblock* checklist = malloc(CHECKLISTMAXPOINTER * sizeof(struct checkblock));

	time_t t;
	struct tm tm;

	u8 temp32[32], i, a;
	u16 cx;
	u64 checklistpointer;
	u64 MaxPointer = 0;
	u64 ResMemCounter = 0;

	uint128 ResCounter = 0;
	uint128 TryCounter, tx;

	#if WRITE_RESULTS2FILE == 1
		struct resblock* results = malloc(SAVE_RESULTS_EVERYN * sizeof(struct resblock));
		FILE *outfile;
		outfile = fopen(RESULTFILENAME, "wb");
	#endif

	TryCounter = 1;

	clock_t tic = clock();

	while (TryCounter > 0)
	{
		#if TRYTEXTOUTPUT == 1
			printf("TryCounter 0x%016llx%016llx ",  (u64)(TryCounter >> 64), (u64)TryCounter);
			printf("ResCounter 0x%016llx%016llx\n", (u64)(ResCounter >> 64), (u64)ResCounter);
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
			#if TRYTEXTOUTPUT == 1
				printf("%02x", a);
			#endif
			a = goodpairs[i*256*2+cx*2+1];
			checklist[checklistpointer].check32[i*2+1] = a;
			#if TRYTEXTOUTPUT == 1
				printf("%02x ", a);
			#endif
		}
		checklist[checklistpointer].iterations = 256;

		#if TRYTEXTOUTPUT == 1
			printf("\n");
		#endif

		TryCounter++;

		while (checklistpointer > 0) {
			if (MaxPointer < checklistpointer)
				MaxPointer = checklistpointer;

			u16 iterations_left = checklist[checklistpointer].iterations;

			if (iterations_left == 0)
			{
				ResCounter++;
				#if WRITE_RESULTS2FILE == 1
					memcpy(results[ResMemCounter].result32, checklist[checklistpointer].check32, 32);
					ResMemCounter++;
					if (ResMemCounter == SAVE_RESULTS_EVERYN)
					{
						fwrite(results, ResMemCounter * sizeof(struct resblock), 1, outfile);
						ResMemCounter = 0;
						t = time(NULL);
						tm = *localtime(&t);
						printf("%d-%02d-%02d %02d:%02d:%02d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
						printf("ResCounter ");
						printbigdec(ResCounter);
						printf(" MaxPointer ");
						printbigdec(MaxPointer);
						printf("\n");
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
				#if WRITE_RESULTS2FILE == 1
					fwrite(results, ResMemCounter * sizeof(struct resblock), 1, outfile);
					fclose(outfile);
					free(results);
				#endif
				free(checklist);
				return 1;
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

		#if EXITAFTER_NPLUSRES > 0
			if (ResCounter >= EXITAFTER_NPLUSRES)
				break;
		#endif
	}

	clock_t toc = clock();

	printf("\nTime       %f seconds", (double)(toc - tic) / CLOCKS_PER_SEC);
	printf("\nResCounter ");
	printbigdec(ResCounter);
	printf("\nTryCounter ");
	printbigdec(TryCounter);
	printf("\nMaxPointer ");
	printbigdec(MaxPointer);
	printf("\n");

	#if WRITE_RESULTS2FILE == 1
		fwrite(results, ResMemCounter * sizeof(struct resblock), 1, outfile);
		fclose(outfile);
		free(results);
	#endif
	free(checklist);
	
	return 0;
}
