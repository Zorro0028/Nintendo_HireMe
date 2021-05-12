# made by Zorro; zorropride gmail
exit_after_Nplusresults = 1
exit_after_Nplusseconds = 5*60
resultsfilename         = "__n_res_py.py"

from n_data import *
import time

def reverse(list32, itercnt):
    if itercnt == 0:
        allres.extend(list32)
        return
    temp32 = list32[:]
    for i in range(32):
        for k in range(14): temp32[i] ^= list32[ xorlist[i][k] ]
        if banned[ temp32[i] ]: return
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

print("exit_after_Nplusresults", exit_after_Nplusresults)
print("exit_after_Nplusseconds", exit_after_Nplusseconds)
print("resultsfilename", resultsfilename)

allres = []
last32 = [0]*32
results_counter = 0
prevr = 0
start_time = time.monotonic()

for trycounter in range(256**16):
    print(trycounter, "> ", end="")
    for n in range(16):
        print(hex((trycounter>>n*8)&0xff)[2:].zfill(2), end=" ")
        last32[n*2]   = goodpairs[n][(trycounter>>n*8)&0xff][0]
        last32[n*2+1] = goodpairs[n][(trycounter>>n*8)&0xff][1]
    print("> results so far =", results_counter)
    reverse(last32, 256)

    results_counter = len(allres) // 32

    if not prevr == results_counter:
        prevr = results_counter
        print("trycounter", trycounter, "results_counter", results_counter)
        if exit_after_Nplusresults > 0 and results_counter >= exit_after_Nplusresults:
            break
        if exit_after_Nplusseconds > 0 and time.monotonic() - start_time >= exit_after_Nplusseconds:
            break

runtime = str(time.monotonic() - start_time) + " seconds"
print("runtime", runtime)

outfile = open(resultsfilename, "w")
outfile.write("# results_counter " + str(results_counter) + "\n")
outfile.write("# trycounter " + str(trycounter) + "\n")
outfile.write("# runtime " + runtime + "\n")
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
