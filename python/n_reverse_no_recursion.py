# made by Zorro; zorropride gmail
exit_after_Nplusresults = 1
exit_after_Nplusseconds = 5*60
resultsfilename         = "__n_res_py_no_recursion.py"
resultsfilenamebin      = "__n_res_py_no_recursion.bin"

from n_data import *
import time

print("exit_after_Nplusresults", exit_after_Nplusresults)
print("exit_after_Nplusseconds", exit_after_Nplusseconds)
print("resultsfilename", resultsfilename)

allres = []
results_counter = 0
temp32 = [0]*32
max_checklistpointer = 0
checklist = [0]*(33*100_000)
start_time = time.monotonic()

for trycounter in range(256**16):
    print(trycounter, "> ", end="")
    for n in range(16):
        print(hex((trycounter>>n*8)&0xff)[2:].zfill(2), end=" ")
        checklist[33+n*2]   = goodpairs[n][(trycounter>>n*8)&0xff][0]
        checklist[33+n*2+1] = goodpairs[n][(trycounter>>n*8)&0xff][1]
    print("> results so far =", results_counter)
    checklist[33+32] = 256

    checklistpointer = 1
    currescnt = 0
    while (checklistpointer > 0):
        if checklistpointer > max_checklistpointer:
            max_checklistpointer = checklistpointer
        list32 = checklist[checklistpointer*33:checklistpointer*33+32]
        itercnt = checklist[checklistpointer*33+32]

        if itercnt == 0:
            allres.extend(list32)
            results_counter += 1
            currescnt += 1
            checklistpointer -= 1
            continue

        temp32 = list32[:]

        bannedflag = 0
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

    if currescnt > 0:
        print("trycounter", trycounter, "results_counter", results_counter)
        if exit_after_Nplusresults > 0 and results_counter >= exit_after_Nplusresults:
            break
        if exit_after_Nplusseconds > 0 and time.monotonic() - start_time >= exit_after_Nplusseconds:
            break

print("max_checklistpointer", max_checklistpointer)

runtime = str(time.monotonic() - start_time) + " seconds"
print("runtime", runtime)

outfile = open(resultsfilename, "w")
outfileb = open(resultsfilenamebin, "wb")
outfile.write("# results_counter " + str(results_counter) + "\n")
outfile.write("# trycounter " + str(trycounter) + "\n")
outfile.write("# max_checklistpointer " + str(max_checklistpointer) + "\n")
outfile.write("# runtime " + runtime + "\n")
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
