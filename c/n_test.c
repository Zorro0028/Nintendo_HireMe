#define ITERATION_COUNT     256
static const char filename[] = "__n_res_c.bin";

typedef unsigned char       u8;
typedef unsigned long long  u64;

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "n_data.inc"

int main(int argc, char* argv[])
{
    u8 target16[]="Hire me!!!!!!!!";
    u8 output16[16], temp32[32], input32[32], i;

    FILE *infile;
    u8 openok = 0;
    infile = fopen(filename, "rb");
    if (infile == NULL) {
        if (argc == 2) {
            infile = fopen(argv[1], "rb");
            if (infile == NULL) {
                printf("FILE NOT FOUND: %s\n", argv[1]);
                return 1;
            }
            openok = 1;
            printf("%s\n", argv[1]);
        }
        if (openok == 0) {
            printf("FILE NOT FOUND: %s\n", filename);
            return 1;
        }
    } else {
        printf("%s\n", filename);
    }

    printf("ITERATION_COUNT = %d\n", ITERATION_COUNT);

    fseek(infile, 0, SEEK_END);
    u64 size = ftell(infile);
    printf("size = %llu\n", size);
    u64 lines = size / 32;
    printf("lines = %llu\n", lines);
    fseek(infile, 0, SEEK_SET);

    while (lines) {
        lines--;
        fread(input32, 32, 1, infile);

        for (int iteration = 0; iteration < ITERATION_COUNT; iteration++)
        {
            for (i = 0; i < 32; i++)
                input32[i] = arr512[ input32[i] ];
            memcpy(temp32, input32, 32);
            #include "n_xor_test.inc"
        }

        for (i = 0; i < 16; i++)
            output16[i] = arr512[ input32[i*2] ] ^ arr512[ 256+input32[i*2+1] ];

        u8 s = memcmp(output16, target16, 16);
        if (s) {
            printf("WRONG RESULT!\n");
            exit(1);
        }
    }

    printf("ALL OK\n");

    fclose(infile);

    return 0;
}
