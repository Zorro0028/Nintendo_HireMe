# 135276
last32 = [
0x26,0x06,0x9a,0x20,0xbf,0x53,0x0f,0xee,0x00,0xa1,0x00,0x1d,0x00,0x7d,0x00,0x85,
0x00,0x85,0x00,0x85,0x00,0x85,0x00,0x85,0x00,0x85,0x00,0x85,0x00,0x85,0x00,0xc8,
]

resultsfilename     = "__n_expander.py"
resultsfilenamebin  = "__n_expander.bin"

from n_data import *
import time

allres = []
results_counter = 0
max_checklistpointer = 0
checklist = [0]*(33*300_000)
start_time = time.monotonic()

for n in range(32):
    checklist[33+n] = last32[n]
checklist[33+32] = 256

print("expanding")

checklistpointer = 1
while (checklistpointer > 0):
    if checklistpointer > max_checklistpointer:
        max_checklistpointer = checklistpointer
    list32 = checklist[checklistpointer*33:checklistpointer*33+32]
    itercnt = checklist[checklistpointer*33+32]

    if itercnt == 0:
        allres.extend(list32)
        results_counter += 1
        checklistpointer -= 1
        continue

    bannedflag = 0
    temp32 = list32[:]
    for i in range(32):
        for k in range(14):
            list32[i] ^= temp32[ xorlist[i][k] ]
        if banned[ list32[i] ]:
            bannedflag = 1
            break
    if bannedflag:
        checklistpointer -= 1
        continue

    rev2cnt = 0
    for i in range(32):
        v = list32[i]
        if rev2[v] > 0:
            rev2cnt += 1

    revscnt = 1 << rev2cnt

    periodval = 1
    periodcnt = periodval
    for i in range(32):
        v = list32[i]
        r2flag = 0
        if rev2[v] > 0:
            for n in range(revscnt):
                if r2flag:
                    checklist[(checklistpointer+n)*33+i] = rev2[v]
                else:
                    checklist[(checklistpointer+n)*33+i] = rev1[v]
                periodcnt -= 1
                if periodcnt == 0:
                    r2flag = 1 - r2flag
                    periodcnt = periodval
            periodval = periodval * 2
        else:
            for n in range(revscnt):
                checklist[(checklistpointer+n)*33+i] = rev1[v]

    for i in range(revscnt):
        checklist[(checklistpointer+i)*33+32] = itercnt-1
    checklistpointer += revscnt-1

runtime = str(time.monotonic() - start_time) + " seconds"
print("runtime", runtime)
print("results_counter", results_counter)
print("max_checklistpointer", max_checklistpointer)

outfile = open(resultsfilename, "w")
outfileb = open(resultsfilenamebin, "wb")
outfile.write("# runtime " + runtime + "\n")
outfile.write("# results_counter " + str(results_counter) + "\n")
outfile.write("# max_checklistpointer " + str(max_checklistpointer) + "\n")
outfile.write("res = {\n")
for k in range(results_counter):
    outfile.write(str(k) + ": [ ")
    outs = ""
    for i in range(32):
        bb = allres[k*32+i]
        wb = bb.to_bytes(1, "little")
        outfileb.write(wb)
        v = hex(bb)
        v = v.replace("0x", "")
        v = v.zfill(2)
        outs += "0x" + str(v) + ","
    outs = outs.rstrip(",")
    outfile.write(outs + " ],\n")
outfile.write("}\n")
outfile.close()
outfileb.close()
