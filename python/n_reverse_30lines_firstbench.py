from n_data import * # made by Zorro; zorropride gmail
import time

def reverse(list32, itercnt):
    if itercnt == 0:
        for i in range(32): print(hex(list32[i]), end=",")
        print("\nruntime", str(time.monotonic() - start_time), "seconds")
        exit()
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

start_time = time.monotonic()
for trycounter in range(256**16):
    last32 = []
    for n in range(16): last32.extend([goodpairs[n][(trycounter>>(n*8))&0xff][0], goodpairs[n][(trycounter>>(n*8))&0xff][1]])
    reverse(last32, 256)
