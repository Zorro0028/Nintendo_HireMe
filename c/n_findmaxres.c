#define START_TRY_HI64		0 // 0x1020304050607080
#define START_TRY_LO64		0 // 0x90a0b0c0d0e0f000
#define USE_RANDOM_TRY		1
#define RANDOM_SEEDVAL		0 // 0xb178416d1c94e5b9
#define RESULTFILENAME		"__n_res_c_maxres.bin"
#define PRINT_TXTDEBUG		0

#define CHECKLISTMAXPOINTER	2000000

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "n_data.inc"
#include "n_misc.inc"

int main(int argc, char* argv[])
{
	printf(" _____\n|[___]|\n|+ c +|\n`-----'\n");

	#if USE_RANDOM_TRY == 1
		printf("  rnd  \n\n");
	#else
		printf("  fix  \n\n");
	#endif

	struct checkblock* checklist = malloc(CHECKLISTMAXPOINTER * sizeof(struct checkblock));

	time_t t;
	struct tm tm;

	u8 temp32[32], i, a, savedlast32[32];
	u16 cx;
	u64 checklistpointer, r, CurLast32Res, MaxLast32Res = 0;
	uint128 TryCounter, tx;

	#if USE_RANDOM_TRY == 1
		srand((u64)**main + (u64)&argc + (u64)time(NULL) + RANDOM_SEEDVAL);
		srand(rand());
	#else
		TryCounter = START_TRY_HI64;
		TryCounter = TryCounter << 64;
		TryCounter += START_TRY_LO64;
		printf("start TryCounter = 0x");
		printbighex(TryCounter);
		printf("\n");
	#endif

	FILE *outfile;
	outfile = fopen(RESULTFILENAME, "wb");
	fclose(outfile);

	while (1) {
		checklistpointer = 1;

		#if USE_RANDOM_TRY == 0
			tx = TryCounter;
		#endif

		for (i = 0; i < 16; i++)
		{
			#if USE_RANDOM_TRY == 1
				r = rand();
				r = r >> 11;
				cx = r & 0xff;
			#else
				cx = tx & 0xff;
				tx = tx >> 8;
			#endif

			#if PRINT_TXTDEBUG == 1
				printf(" %02x  ", cx);
			#endif

			a = goodpairs[i*256*2+cx*2];
			checklist[checklistpointer].check32[i*2] = a;
			a = goodpairs[i*256*2+cx*2+1];
			checklist[checklistpointer].check32[i*2+1] = a;
		}
		#if PRINT_TXTDEBUG == 1
			printf("\n");
		#endif

		#if USE_RANDOM_TRY == 0
			TryCounter++;
		#endif

		checklist[checklistpointer].iterations = 256;

		memcpy(&savedlast32, &checklist[checklistpointer].check32, 32);

		#if PRINT_TXTDEBUG == 1
			for (i = 0; i < 32; i++) {
				r = checklist[checklistpointer].check32[i];
				printf("%02x", r);
				if ((i % 2 == 1))
					printf(" ");
			}
			printf("\n");
		#endif

		CurLast32Res = 0;

		while (checklistpointer > 0) {
			u16 iterations_left = checklist[checklistpointer].iterations;

			if (iterations_left == 0)
			{
				CurLast32Res++;
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
				fclose(outfile);
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

		if (CurLast32Res > MaxLast32Res) {
			MaxLast32Res = CurLast32Res;
			printf("%llu\n", MaxLast32Res);
			outfile = fopen(RESULTFILENAME, "ab");
			fwrite(&MaxLast32Res, 8, 1, outfile);
			tx = 0;
			fwrite(&tx, 8, 1, outfile);
			fwrite(&savedlast32, 32, 1, outfile);
			fclose(outfile);
		}
	}

	free(checklist);
	
	return 0;
}
