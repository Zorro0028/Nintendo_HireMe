// made by Zorro; zorropride gmail
#define EXITAFTER_NRESULTS	1
#define TRYTEXTOUTPUT		1
#define WRITE_RESULTS2FILE	1

// // one million results benchmark
// #define EXITAFTER_NRESULTS	1000000
// #define TRYTEXTOUTPUT		0
// #define WRITE_RESULTS2FILE	0

#define RESULTFILENAME		"__n_res_c.bin"

#define MAXRESULTS			10000000
#define CHECKLISTMAXPOINTER	100000
#define MAXTRY				0xffffffffffffffff // only 64bit trycounter, max 256^8 variants output

typedef unsigned char		u8;
typedef unsigned long long	u64;
typedef unsigned short int	u16;

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

int main(int argc, char* argv[])
{
	printf(" _____\n|[___]|\n|+ c +|\n`-----'\nloading\n\n");

	struct checkblock* checklist = malloc(CHECKLISTMAXPOINTER * sizeof(struct checkblock));
	struct     resblock* results = malloc((MAXRESULTS+1)      * sizeof(struct resblock));
	clock_t tic = clock();
	u8 temp32[32], i, a;
	u16 cx;
	u64 checklistpointer, tx;
	FILE *outfile;
	u64 MaxPointer = 0;
	u64 AllResCounter = 0;
	u64 trycounter = 0;

	for (; trycounter < MAXTRY; trycounter++)
	{
		#if TRYTEXTOUTPUT == 1
		printf("%llu > ", trycounter);
		#endif

		checklistpointer = 1;
		tx = trycounter;
		for (i = 0; i < 16; i++)
		{
			cx = tx & 0xff;
			#if TRYTEXTOUTPUT == 1
			printf("%02x ", cx);
			#endif
			tx = tx >> 8;
			a = goodpairs[i*256*2+cx*2];
			checklist[checklistpointer].check32[i*2] = a;
			a = goodpairs[i*256*2+cx*2+1];
			checklist[checklistpointer].check32[i*2+1] = a;
		}
		checklist[checklistpointer].iterations = 256;

		#if TRYTEXTOUTPUT == 1
		printf("> results so far = %d\n", AllResCounter);
		#endif

		while (checklistpointer > 0) {
			if (MaxPointer < checklistpointer)
				MaxPointer = checklistpointer;

			u16 iterations_left = checklist[checklistpointer].iterations;

			if (iterations_left == 0)
			{
				memcpy(results[AllResCounter].result32, checklist[checklistpointer].check32, 32);
				AllResCounter++;
				if (AllResCounter == MAXRESULTS)
					break;
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

		if (AllResCounter == MAXRESULTS)
			break;

		#if EXITAFTER_NRESULTS > 0
		if (AllResCounter >= EXITAFTER_NRESULTS)
			break;
		#endif
	}

	clock_t toc = clock();
	printf("time = %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	printf("trycounter = %llu\n", trycounter);
	printf("MaxPointer = %llu\n", MaxPointer);
	printf("AllResCounter = %d\n", AllResCounter);

	#if WRITE_RESULTS2FILE == 1
	outfile = fopen(RESULTFILENAME, "wb");
	fwrite(results, AllResCounter * sizeof(struct resblock), 1, outfile);
	fclose(outfile);
	#endif

	free(results);
	free(checklist);
	
	return 0;
}
