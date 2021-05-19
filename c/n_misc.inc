typedef unsigned char		u8;
typedef unsigned long long	u64;
typedef unsigned short int	u16;
typedef unsigned __int128	uint128;


struct checkblock {
	u8	check32[32];
	u16	iterations;
};


struct resblock {
	u8	result32[32];
};


int printbigdec(uint128 tx) {
	u8 bigdec[64], dx, dd;
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
		dd = bigdec[64-dnum+dx];
		if (dd == 111)
			printf("_");
		else
			printf("%c", dd+'0');
	}
	return 1;
}


int printbighex(uint128 tx) {
	u8 bigdec[32], dx, hd, dnum = 0;
	for (u8 i = 0; i < 32; i++) {
		dx = tx & 0xf;
		tx = tx >> 4;
		bigdec[32-dnum-1] = dx;
		dnum++;
	}
	for (dx = 0; dx < dnum; dx++) {
		hd = bigdec[32-dnum+dx];
		if (hd > 9)
			printf("%c", hd-10+'a');
		else
			printf("%c", hd+'0');
	}
	return 1;
}
