# 430281
last32 = [
0x72,0x73,0x09,0x5e,0x6d,0x09,0xf0,0x69,0x92,0x14,0x35,0xbb,0x20,0x60,0xe5,0x4d,0xb1,0xab,0xf1,0x13,0xab,0xc8,0x69,0x0a,0x05,0x51,0x32,0xdc,0xc8,0x6e,0x1c,0x4e,
]

resultsfilename     = "__n_expander_xu_430281.py"

from n_data import *
import time

def reverse(list32, itercnt):
    if itercnt == 0:
        allres.extend(list32)
        return
    temp32 = list32[:]

    a = temp32[0]
    a ^= list32[7]
    a ^= list32[10]
    a ^= list32[12]
    a ^= list32[13]
    a ^= list32[15]
    a ^= list32[18]
    a ^= list32[19]
    a ^= list32[21]
    a ^= list32[22]
    a ^= list32[25]
    a ^= list32[28]
    a ^= list32[29]
    a ^= list32[30]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[0] = a
    a = temp32[1]
    a ^= list32[4]
    a ^= list32[7]
    a ^= list32[10]
    a ^= list32[11]
    a ^= list32[12]
    a ^= list32[14]
    a ^= list32[15]
    a ^= list32[16]
    a ^= list32[18]
    a ^= list32[21]
    a ^= list32[23]
    a ^= list32[25]
    a ^= list32[26]
    a ^= list32[28]
    if banned[a]:
        return
    temp32[1] = a
    a = temp32[2]
    a ^= list32[5]
    a ^= list32[8]
    a ^= list32[11]
    a ^= list32[13]
    a ^= list32[15]
    a ^= list32[16]
    a ^= list32[17]
    a ^= list32[19]
    a ^= list32[20]
    a ^= list32[22]
    a ^= list32[26]
    a ^= list32[27]
    a ^= list32[28]
    a ^= list32[29]
    if banned[a]:
        return
    temp32[2] = a
    a = temp32[3]
    a ^= list32[6]
    a ^= list32[9]
    a ^= list32[12]
    a ^= list32[14]
    a ^= list32[17]
    a ^= list32[18]
    a ^= list32[20]
    a ^= list32[21]
    a ^= list32[23]
    a ^= list32[24]
    a ^= list32[27]
    a ^= list32[28]
    a ^= list32[29]
    a ^= list32[30]
    if banned[a]:
        return
    temp32[3] = a
    a = temp32[4]
    a ^= list32[3]
    a ^= list32[8]
    a ^= list32[9]
    a ^= list32[11]
    a ^= list32[14]
    a ^= list32[17]
    a ^= list32[18]
    a ^= list32[22]
    a ^= list32[23]
    a ^= list32[24]
    a ^= list32[25]
    a ^= list32[26]
    a ^= list32[27]
    a ^= list32[29]
    if banned[a]:
        return
    temp32[4] = a
    a = temp32[5]
    a ^= list32[0]
    a ^= list32[3]
    a ^= list32[8]
    a ^= list32[10]
    a ^= list32[11]
    a ^= list32[14]
    a ^= list32[15]
    a ^= list32[17]
    a ^= list32[19]
    a ^= list32[20]
    a ^= list32[22]
    a ^= list32[24]
    a ^= list32[29]
    a ^= list32[30]
    if banned[a]:
        return
    temp32[5] = a
    a = temp32[6]
    a ^= list32[1]
    a ^= list32[9]
    a ^= list32[11]
    a ^= list32[12]
    a ^= list32[15]
    a ^= list32[16]
    a ^= list32[18]
    a ^= list32[20]
    a ^= list32[21]
    a ^= list32[23]
    a ^= list32[24]
    a ^= list32[25]
    a ^= list32[30]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[6] = a
    a = temp32[7]
    a ^= list32[2]
    a ^= list32[8]
    a ^= list32[10]
    a ^= list32[13]
    a ^= list32[16]
    a ^= list32[17]
    a ^= list32[19]
    a ^= list32[21]
    a ^= list32[22]
    a ^= list32[24]
    a ^= list32[25]
    a ^= list32[26]
    a ^= list32[28]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[7] = a
    a = temp32[8]
    a ^= list32[2]
    a ^= list32[4]
    a ^= list32[5]
    a ^= list32[7]
    a ^= list32[15]
    a ^= list32[17]
    a ^= list32[20]
    a ^= list32[21]
    a ^= list32[22]
    a ^= list32[23]
    a ^= list32[26]
    a ^= list32[27]
    a ^= list32[29]
    a ^= list32[30]
    if banned[a]:
        return
    temp32[8] = a
    a = temp32[9]
    a ^= list32[2]
    a ^= list32[3]
    a ^= list32[4]
    a ^= list32[6]
    a ^= list32[7]
    a ^= list32[12]
    a ^= list32[15]
    a ^= list32[17]
    a ^= list32[18]
    a ^= list32[20]
    a ^= list32[24]
    a ^= list32[26]
    a ^= list32[29]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[9] = a
    a = temp32[10]
    a ^= list32[0]
    a ^= list32[3]
    a ^= list32[5]
    a ^= list32[7]
    a ^= list32[13]
    a ^= list32[18]
    a ^= list32[19]
    a ^= list32[20]
    a ^= list32[21]
    a ^= list32[24]
    a ^= list32[25]
    a ^= list32[27]
    a ^= list32[28]
    a ^= list32[30]
    if banned[a]:
        return
    temp32[10] = a
    a = temp32[11]
    a ^= list32[1]
    a ^= list32[4]
    a ^= list32[6]
    a ^= list32[14]
    a ^= list32[16]
    a ^= list32[19]
    a ^= list32[20]
    a ^= list32[21]
    a ^= list32[22]
    a ^= list32[25]
    a ^= list32[26]
    a ^= list32[28]
    a ^= list32[29]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[11] = a
    a = temp32[12]
    a ^= list32[0]
    a ^= list32[1]
    a ^= list32[3]
    a ^= list32[6]
    a ^= list32[11]
    a ^= list32[16]
    a ^= list32[17]
    a ^= list32[18]
    a ^= list32[19]
    a ^= list32[21]
    a ^= list32[25]
    a ^= list32[26]
    a ^= list32[30]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[12] = a
    a = temp32[13]
    a ^= list32[0]
    a ^= list32[2]
    a ^= list32[3]
    a ^= list32[6]
    a ^= list32[7]
    a ^= list32[8]
    a ^= list32[11]
    a ^= list32[16]
    a ^= list32[21]
    a ^= list32[22]
    a ^= list32[25]
    a ^= list32[27]
    a ^= list32[28]
    a ^= list32[30]
    if banned[a]:
        return
    temp32[13] = a
    a = temp32[14]
    a ^= list32[1]
    a ^= list32[3]
    a ^= list32[4]
    a ^= list32[7]
    a ^= list32[9]
    a ^= list32[16]
    a ^= list32[17]
    a ^= list32[22]
    a ^= list32[23]
    a ^= list32[24]
    a ^= list32[26]
    a ^= list32[28]
    a ^= list32[29]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[14] = a
    a = temp32[15]
    a ^= list32[0]
    a ^= list32[2]
    a ^= list32[5]
    a ^= list32[10]
    a ^= list32[16]
    a ^= list32[17]
    a ^= list32[18]
    a ^= list32[20]
    a ^= list32[23]
    a ^= list32[24]
    a ^= list32[25]
    a ^= list32[27]
    a ^= list32[29]
    a ^= list32[30]
    if banned[a]:
        return
    temp32[15] = a
    a = temp32[16]
    a ^= list32[2]
    a ^= list32[3]
    a ^= list32[5]
    a ^= list32[6]
    a ^= list32[9]
    a ^= list32[12]
    a ^= list32[13]
    a ^= list32[14]
    a ^= list32[15]
    a ^= list32[23]
    a ^= list32[26]
    a ^= list32[28]
    a ^= list32[29]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[16] = a
    a = temp32[17]
    a ^= list32[0]
    a ^= list32[2]
    a ^= list32[5]
    a ^= list32[7]
    a ^= list32[9]
    a ^= list32[10]
    a ^= list32[12]
    a ^= list32[20]
    a ^= list32[23]
    a ^= list32[26]
    a ^= list32[27]
    a ^= list32[28]
    a ^= list32[30]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[17] = a
    a = temp32[18]
    a ^= list32[0]
    a ^= list32[1]
    a ^= list32[3]
    a ^= list32[4]
    a ^= list32[6]
    a ^= list32[10]
    a ^= list32[11]
    a ^= list32[12]
    a ^= list32[13]
    a ^= list32[21]
    a ^= list32[24]
    a ^= list32[27]
    a ^= list32[29]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[18] = a
    a = temp32[19]
    a ^= list32[1]
    a ^= list32[2]
    a ^= list32[4]
    a ^= list32[5]
    a ^= list32[7]
    a ^= list32[8]
    a ^= list32[11]
    a ^= list32[12]
    a ^= list32[13]
    a ^= list32[14]
    a ^= list32[22]
    a ^= list32[25]
    a ^= list32[28]
    a ^= list32[30]
    if banned[a]:
        return
    temp32[19] = a
    a = temp32[20]
    a ^= list32[1]
    a ^= list32[2]
    a ^= list32[6]
    a ^= list32[7]
    a ^= list32[8]
    a ^= list32[9]
    a ^= list32[10]
    a ^= list32[11]
    a ^= list32[13]
    a ^= list32[19]
    a ^= list32[24]
    a ^= list32[25]
    a ^= list32[27]
    a ^= list32[30]
    if banned[a]:
        return
    temp32[20] = a
    a = temp32[21]
    a ^= list32[1]
    a ^= list32[3]
    a ^= list32[4]
    a ^= list32[6]
    a ^= list32[8]
    a ^= list32[13]
    a ^= list32[14]
    a ^= list32[16]
    a ^= list32[19]
    a ^= list32[24]
    a ^= list32[26]
    a ^= list32[27]
    a ^= list32[30]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[21] = a
    a = temp32[22]
    a ^= list32[0]
    a ^= list32[2]
    a ^= list32[4]
    a ^= list32[5]
    a ^= list32[7]
    a ^= list32[8]
    a ^= list32[9]
    a ^= list32[14]
    a ^= list32[15]
    a ^= list32[17]
    a ^= list32[25]
    a ^= list32[27]
    a ^= list32[28]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[22] = a
    a = temp32[23]
    a ^= list32[0]
    a ^= list32[1]
    a ^= list32[3]
    a ^= list32[5]
    a ^= list32[6]
    a ^= list32[8]
    a ^= list32[9]
    a ^= list32[10]
    a ^= list32[12]
    a ^= list32[15]
    a ^= list32[18]
    a ^= list32[24]
    a ^= list32[26]
    a ^= list32[29]
    if banned[a]:
        return
    temp32[23] = a
    a = temp32[24]
    a ^= list32[1]
    a ^= list32[4]
    a ^= list32[5]
    a ^= list32[6]
    a ^= list32[7]
    a ^= list32[10]
    a ^= list32[11]
    a ^= list32[13]
    a ^= list32[14]
    a ^= list32[18]
    a ^= list32[20]
    a ^= list32[21]
    a ^= list32[23]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[24] = a
    a = temp32[25]
    a ^= list32[1]
    a ^= list32[2]
    a ^= list32[4]
    a ^= list32[8]
    a ^= list32[10]
    a ^= list32[13]
    a ^= list32[15]
    a ^= list32[18]
    a ^= list32[19]
    a ^= list32[20]
    a ^= list32[22]
    a ^= list32[23]
    a ^= list32[28]
    a ^= list32[31]
    if banned[a]:
        return
    temp32[25] = a
    a = temp32[26]
    a ^= list32[2]
    a ^= list32[3]
    a ^= list32[4]
    a ^= list32[5]
    a ^= list32[8]
    a ^= list32[9]
    a ^= list32[11]
    a ^= list32[12]
    a ^= list32[14]
    a ^= list32[16]
    a ^= list32[19]
    a ^= list32[21]
    a ^= list32[23]
    a ^= list32[29]
    if banned[a]:
        return
    temp32[26] = a
    a = temp32[27]
    a ^= list32[0]
    a ^= list32[3]
    a ^= list32[4]
    a ^= list32[5]
    a ^= list32[6]
    a ^= list32[9]
    a ^= list32[10]
    a ^= list32[12]
    a ^= list32[13]
    a ^= list32[15]
    a ^= list32[17]
    a ^= list32[20]
    a ^= list32[22]
    a ^= list32[30]
    if banned[a]:
        return
    temp32[27] = a
    a = temp32[28]
    a ^= list32[0]
    a ^= list32[1]
    a ^= list32[2]
    a ^= list32[3]
    a ^= list32[5]
    a ^= list32[9]
    a ^= list32[10]
    a ^= list32[14]
    a ^= list32[15]
    a ^= list32[16]
    a ^= list32[17]
    a ^= list32[19]
    a ^= list32[22]
    a ^= list32[27]
    if banned[a]:
        return
    temp32[28] = a
    a = temp32[29]
    a ^= list32[0]
    a ^= list32[5]
    a ^= list32[6]
    a ^= list32[9]
    a ^= list32[11]
    a ^= list32[12]
    a ^= list32[14]
    a ^= list32[16]
    a ^= list32[18]
    a ^= list32[19]
    a ^= list32[22]
    a ^= list32[23]
    a ^= list32[24]
    a ^= list32[27]
    if banned[a]:
        return
    temp32[29] = a
    a = temp32[30]
    a ^= list32[0]
    a ^= list32[1]
    a ^= list32[6]
    a ^= list32[7]
    a ^= list32[8]
    a ^= list32[10]
    a ^= list32[12]
    a ^= list32[13]
    a ^= list32[15]
    a ^= list32[17]
    a ^= list32[19]
    a ^= list32[20]
    a ^= list32[23]
    a ^= list32[25]
    if banned[a]:
        return
    temp32[30] = a
    a = temp32[31]
    a ^= list32[0]
    a ^= list32[1]
    a ^= list32[2]
    a ^= list32[4]
    a ^= list32[7]
    a ^= list32[8]
    a ^= list32[9]
    a ^= list32[11]
    a ^= list32[13]
    a ^= list32[14]
    a ^= list32[16]
    a ^= list32[18]
    a ^= list32[21]
    a ^= list32[26]
    if banned[a]:
        return
    temp32[31] = a

    revlist = genallrevs(0, temp32)
    for r in range(len(revlist)//32):
        reverse(revlist[r*32:r*32+32], itercnt-1)

def genallrevs(startn, final32):
    if startn == 32:
        return final32
    next32 = final32[:]
    res = []
    if rev2[final32[startn]] > 0:
        next32[startn] = rev2[final32[startn]]
        res.extend(genallrevs(startn+1, next32))
    next32[startn] = rev1[final32[startn]]
    res.extend(genallrevs(startn+1, next32))
    return res

print("expanding")

start_time = time.monotonic()
allres = []
results_counter = 0
prevr = 0

reverse(last32, 256)

runtime = str(time.monotonic() - start_time) + " seconds"
print("runtime", runtime)
results_counter = len(allres) // 32
print("results_counter", results_counter)

outfile = open(resultsfilename, "w")
outfile.write("# results_counter " + str(results_counter) + "\n")
outfile.write("# runtime " + str(runtime) + "\n")
outfile.write("res = {\n")
for k in range(results_counter):
    outfile.write(str(k) + ": [ ")
    outs = ""
    for i in range(32):
        v = hex(allres[k*32+i])
        v = v.replace("0x", "")
        v = v.zfill(2)
        outs += "0x" + str(v) + ","
    outs = outs.rstrip(",")
    outfile.write(outs + " ],\n")
outfile.write("}\n")
outfile.close()
