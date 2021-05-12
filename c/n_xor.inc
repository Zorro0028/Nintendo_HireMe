	a = checklist[checklistpointer].check32[0];
	a ^= temp32[7];
	a ^= temp32[10];
	a ^= temp32[12];
	a ^= temp32[13];
	a ^= temp32[15];
	a ^= temp32[18];
	a ^= temp32[19];
	a ^= temp32[21];
	a ^= temp32[22];
	a ^= temp32[25];
	a ^= temp32[28];
	a ^= temp32[29];
	a ^= temp32[30];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[0] = a;
	a = checklist[checklistpointer].check32[1];
	a ^= temp32[4];
	a ^= temp32[7];
	a ^= temp32[10];
	a ^= temp32[11];
	a ^= temp32[12];
	a ^= temp32[14];
	a ^= temp32[15];
	a ^= temp32[16];
	a ^= temp32[18];
	a ^= temp32[21];
	a ^= temp32[23];
	a ^= temp32[25];
	a ^= temp32[26];
	a ^= temp32[28];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[1] = a;
	a = checklist[checklistpointer].check32[2];
	a ^= temp32[5];
	a ^= temp32[8];
	a ^= temp32[11];
	a ^= temp32[13];
	a ^= temp32[15];
	a ^= temp32[16];
	a ^= temp32[17];
	a ^= temp32[19];
	a ^= temp32[20];
	a ^= temp32[22];
	a ^= temp32[26];
	a ^= temp32[27];
	a ^= temp32[28];
	a ^= temp32[29];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[2] = a;
	a = checklist[checklistpointer].check32[3];
	a ^= temp32[6];
	a ^= temp32[9];
	a ^= temp32[12];
	a ^= temp32[14];
	a ^= temp32[17];
	a ^= temp32[18];
	a ^= temp32[20];
	a ^= temp32[21];
	a ^= temp32[23];
	a ^= temp32[24];
	a ^= temp32[27];
	a ^= temp32[28];
	a ^= temp32[29];
	a ^= temp32[30];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[3] = a;
	a = checklist[checklistpointer].check32[4];
	a ^= temp32[3];
	a ^= temp32[8];
	a ^= temp32[9];
	a ^= temp32[11];
	a ^= temp32[14];
	a ^= temp32[17];
	a ^= temp32[18];
	a ^= temp32[22];
	a ^= temp32[23];
	a ^= temp32[24];
	a ^= temp32[25];
	a ^= temp32[26];
	a ^= temp32[27];
	a ^= temp32[29];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[4] = a;
	a = checklist[checklistpointer].check32[5];
	a ^= temp32[0];
	a ^= temp32[3];
	a ^= temp32[8];
	a ^= temp32[10];
	a ^= temp32[11];
	a ^= temp32[14];
	a ^= temp32[15];
	a ^= temp32[17];
	a ^= temp32[19];
	a ^= temp32[20];
	a ^= temp32[22];
	a ^= temp32[24];
	a ^= temp32[29];
	a ^= temp32[30];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[5] = a;
	a = checklist[checklistpointer].check32[6];
	a ^= temp32[1];
	a ^= temp32[9];
	a ^= temp32[11];
	a ^= temp32[12];
	a ^= temp32[15];
	a ^= temp32[16];
	a ^= temp32[18];
	a ^= temp32[20];
	a ^= temp32[21];
	a ^= temp32[23];
	a ^= temp32[24];
	a ^= temp32[25];
	a ^= temp32[30];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[6] = a;
	a = checklist[checklistpointer].check32[7];
	a ^= temp32[2];
	a ^= temp32[8];
	a ^= temp32[10];
	a ^= temp32[13];
	a ^= temp32[16];
	a ^= temp32[17];
	a ^= temp32[19];
	a ^= temp32[21];
	a ^= temp32[22];
	a ^= temp32[24];
	a ^= temp32[25];
	a ^= temp32[26];
	a ^= temp32[28];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[7] = a;
	a = checklist[checklistpointer].check32[8];
	a ^= temp32[2];
	a ^= temp32[4];
	a ^= temp32[5];
	a ^= temp32[7];
	a ^= temp32[15];
	a ^= temp32[17];
	a ^= temp32[20];
	a ^= temp32[21];
	a ^= temp32[22];
	a ^= temp32[23];
	a ^= temp32[26];
	a ^= temp32[27];
	a ^= temp32[29];
	a ^= temp32[30];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[8] = a;
	a = checklist[checklistpointer].check32[9];
	a ^= temp32[2];
	a ^= temp32[3];
	a ^= temp32[4];
	a ^= temp32[6];
	a ^= temp32[7];
	a ^= temp32[12];
	a ^= temp32[15];
	a ^= temp32[17];
	a ^= temp32[18];
	a ^= temp32[20];
	a ^= temp32[24];
	a ^= temp32[26];
	a ^= temp32[29];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[9] = a;
	a = checklist[checklistpointer].check32[10];
	a ^= temp32[0];
	a ^= temp32[3];
	a ^= temp32[5];
	a ^= temp32[7];
	a ^= temp32[13];
	a ^= temp32[18];
	a ^= temp32[19];
	a ^= temp32[20];
	a ^= temp32[21];
	a ^= temp32[24];
	a ^= temp32[25];
	a ^= temp32[27];
	a ^= temp32[28];
	a ^= temp32[30];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[10] = a;
	a = checklist[checklistpointer].check32[11];
	a ^= temp32[1];
	a ^= temp32[4];
	a ^= temp32[6];
	a ^= temp32[14];
	a ^= temp32[16];
	a ^= temp32[19];
	a ^= temp32[20];
	a ^= temp32[21];
	a ^= temp32[22];
	a ^= temp32[25];
	a ^= temp32[26];
	a ^= temp32[28];
	a ^= temp32[29];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[11] = a;
	a = checklist[checklistpointer].check32[12];
	a ^= temp32[0];
	a ^= temp32[1];
	a ^= temp32[3];
	a ^= temp32[6];
	a ^= temp32[11];
	a ^= temp32[16];
	a ^= temp32[17];
	a ^= temp32[18];
	a ^= temp32[19];
	a ^= temp32[21];
	a ^= temp32[25];
	a ^= temp32[26];
	a ^= temp32[30];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[12] = a;
	a = checklist[checklistpointer].check32[13];
	a ^= temp32[0];
	a ^= temp32[2];
	a ^= temp32[3];
	a ^= temp32[6];
	a ^= temp32[7];
	a ^= temp32[8];
	a ^= temp32[11];
	a ^= temp32[16];
	a ^= temp32[21];
	a ^= temp32[22];
	a ^= temp32[25];
	a ^= temp32[27];
	a ^= temp32[28];
	a ^= temp32[30];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[13] = a;
	a = checklist[checklistpointer].check32[14];
	a ^= temp32[1];
	a ^= temp32[3];
	a ^= temp32[4];
	a ^= temp32[7];
	a ^= temp32[9];
	a ^= temp32[16];
	a ^= temp32[17];
	a ^= temp32[22];
	a ^= temp32[23];
	a ^= temp32[24];
	a ^= temp32[26];
	a ^= temp32[28];
	a ^= temp32[29];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[14] = a;
	a = checklist[checklistpointer].check32[15];
	a ^= temp32[0];
	a ^= temp32[2];
	a ^= temp32[5];
	a ^= temp32[10];
	a ^= temp32[16];
	a ^= temp32[17];
	a ^= temp32[18];
	a ^= temp32[20];
	a ^= temp32[23];
	a ^= temp32[24];
	a ^= temp32[25];
	a ^= temp32[27];
	a ^= temp32[29];
	a ^= temp32[30];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[15] = a;
	a = checklist[checklistpointer].check32[16];
	a ^= temp32[2];
	a ^= temp32[3];
	a ^= temp32[5];
	a ^= temp32[6];
	a ^= temp32[9];
	a ^= temp32[12];
	a ^= temp32[13];
	a ^= temp32[14];
	a ^= temp32[15];
	a ^= temp32[23];
	a ^= temp32[26];
	a ^= temp32[28];
	a ^= temp32[29];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[16] = a;
	a = checklist[checklistpointer].check32[17];
	a ^= temp32[0];
	a ^= temp32[2];
	a ^= temp32[5];
	a ^= temp32[7];
	a ^= temp32[9];
	a ^= temp32[10];
	a ^= temp32[12];
	a ^= temp32[20];
	a ^= temp32[23];
	a ^= temp32[26];
	a ^= temp32[27];
	a ^= temp32[28];
	a ^= temp32[30];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[17] = a;
	a = checklist[checklistpointer].check32[18];
	a ^= temp32[0];
	a ^= temp32[1];
	a ^= temp32[3];
	a ^= temp32[4];
	a ^= temp32[6];
	a ^= temp32[10];
	a ^= temp32[11];
	a ^= temp32[12];
	a ^= temp32[13];
	a ^= temp32[21];
	a ^= temp32[24];
	a ^= temp32[27];
	a ^= temp32[29];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[18] = a;
	a = checklist[checklistpointer].check32[19];
	a ^= temp32[1];
	a ^= temp32[2];
	a ^= temp32[4];
	a ^= temp32[5];
	a ^= temp32[7];
	a ^= temp32[8];
	a ^= temp32[11];
	a ^= temp32[12];
	a ^= temp32[13];
	a ^= temp32[14];
	a ^= temp32[22];
	a ^= temp32[25];
	a ^= temp32[28];
	a ^= temp32[30];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[19] = a;
	a = checklist[checklistpointer].check32[20];
	a ^= temp32[1];
	a ^= temp32[2];
	a ^= temp32[6];
	a ^= temp32[7];
	a ^= temp32[8];
	a ^= temp32[9];
	a ^= temp32[10];
	a ^= temp32[11];
	a ^= temp32[13];
	a ^= temp32[19];
	a ^= temp32[24];
	a ^= temp32[25];
	a ^= temp32[27];
	a ^= temp32[30];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[20] = a;
	a = checklist[checklistpointer].check32[21];
	a ^= temp32[1];
	a ^= temp32[3];
	a ^= temp32[4];
	a ^= temp32[6];
	a ^= temp32[8];
	a ^= temp32[13];
	a ^= temp32[14];
	a ^= temp32[16];
	a ^= temp32[19];
	a ^= temp32[24];
	a ^= temp32[26];
	a ^= temp32[27];
	a ^= temp32[30];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[21] = a;
	a = checklist[checklistpointer].check32[22];
	a ^= temp32[0];
	a ^= temp32[2];
	a ^= temp32[4];
	a ^= temp32[5];
	a ^= temp32[7];
	a ^= temp32[8];
	a ^= temp32[9];
	a ^= temp32[14];
	a ^= temp32[15];
	a ^= temp32[17];
	a ^= temp32[25];
	a ^= temp32[27];
	a ^= temp32[28];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[22] = a;
	a = checklist[checklistpointer].check32[23];
	a ^= temp32[0];
	a ^= temp32[1];
	a ^= temp32[3];
	a ^= temp32[5];
	a ^= temp32[6];
	a ^= temp32[8];
	a ^= temp32[9];
	a ^= temp32[10];
	a ^= temp32[12];
	a ^= temp32[15];
	a ^= temp32[18];
	a ^= temp32[24];
	a ^= temp32[26];
	a ^= temp32[29];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[23] = a;
	a = checklist[checklistpointer].check32[24];
	a ^= temp32[1];
	a ^= temp32[4];
	a ^= temp32[5];
	a ^= temp32[6];
	a ^= temp32[7];
	a ^= temp32[10];
	a ^= temp32[11];
	a ^= temp32[13];
	a ^= temp32[14];
	a ^= temp32[18];
	a ^= temp32[20];
	a ^= temp32[21];
	a ^= temp32[23];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[24] = a;
	a = checklist[checklistpointer].check32[25];
	a ^= temp32[1];
	a ^= temp32[2];
	a ^= temp32[4];
	a ^= temp32[8];
	a ^= temp32[10];
	a ^= temp32[13];
	a ^= temp32[15];
	a ^= temp32[18];
	a ^= temp32[19];
	a ^= temp32[20];
	a ^= temp32[22];
	a ^= temp32[23];
	a ^= temp32[28];
	a ^= temp32[31];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[25] = a;
	a = checklist[checklistpointer].check32[26];
	a ^= temp32[2];
	a ^= temp32[3];
	a ^= temp32[4];
	a ^= temp32[5];
	a ^= temp32[8];
	a ^= temp32[9];
	a ^= temp32[11];
	a ^= temp32[12];
	a ^= temp32[14];
	a ^= temp32[16];
	a ^= temp32[19];
	a ^= temp32[21];
	a ^= temp32[23];
	a ^= temp32[29];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[26] = a;
	a = checklist[checklistpointer].check32[27];
	a ^= temp32[0];
	a ^= temp32[3];
	a ^= temp32[4];
	a ^= temp32[5];
	a ^= temp32[6];
	a ^= temp32[9];
	a ^= temp32[10];
	a ^= temp32[12];
	a ^= temp32[13];
	a ^= temp32[15];
	a ^= temp32[17];
	a ^= temp32[20];
	a ^= temp32[22];
	a ^= temp32[30];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[27] = a;
	a = checklist[checklistpointer].check32[28];
	a ^= temp32[0];
	a ^= temp32[1];
	a ^= temp32[2];
	a ^= temp32[3];
	a ^= temp32[5];
	a ^= temp32[9];
	a ^= temp32[10];
	a ^= temp32[14];
	a ^= temp32[15];
	a ^= temp32[16];
	a ^= temp32[17];
	a ^= temp32[19];
	a ^= temp32[22];
	a ^= temp32[27];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[28] = a;
	a = checklist[checklistpointer].check32[29];
	a ^= temp32[0];
	a ^= temp32[5];
	a ^= temp32[6];
	a ^= temp32[9];
	a ^= temp32[11];
	a ^= temp32[12];
	a ^= temp32[14];
	a ^= temp32[16];
	a ^= temp32[18];
	a ^= temp32[19];
	a ^= temp32[22];
	a ^= temp32[23];
	a ^= temp32[24];
	a ^= temp32[27];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[29] = a;
	a = checklist[checklistpointer].check32[30];
	a ^= temp32[0];
	a ^= temp32[1];
	a ^= temp32[6];
	a ^= temp32[7];
	a ^= temp32[8];
	a ^= temp32[10];
	a ^= temp32[12];
	a ^= temp32[13];
	a ^= temp32[15];
	a ^= temp32[17];
	a ^= temp32[19];
	a ^= temp32[20];
	a ^= temp32[23];
	a ^= temp32[25];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[30] = a;
	a = checklist[checklistpointer].check32[31];
	a ^= temp32[0];
	a ^= temp32[1];
	a ^= temp32[2];
	a ^= temp32[4];
	a ^= temp32[7];
	a ^= temp32[8];
	a ^= temp32[9];
	a ^= temp32[11];
	a ^= temp32[13];
	a ^= temp32[14];
	a ^= temp32[16];
	a ^= temp32[18];
	a ^= temp32[21];
	a ^= temp32[26];
	if (banned[a] == 1) {
		checklistpointer--;
		continue;
	}
	checklist[checklistpointer].check32[31] = a;
