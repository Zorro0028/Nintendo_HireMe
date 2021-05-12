from n_data import *
import random


def th(val):
    v = hex(val)
    v = v.replace("0x", "")
    v = v.zfill(2)
    return v


def geth(val):
    v = hex(val)
    v = v.replace("0x", "")
    v = v.zfill(2)
    return v


def print256(arr):
    print()
    for pil in range(16):
        for pir in range(16):
            try:
                v = arr[pil*16+pir]
            except:
                break
            if v >= 0:
                v = hex(v)
                v = v.replace("0x", "")
                v = v.zfill(2)
                v = v.rjust(4)
            else:
                v = "  --"
            print(v, end=" ")
        print()
    print()


def print256z(arr):
    print()
    for pil in range(16):
        for pir in range(16):
            v = arr[pil*16+pir]
            if v > 0:
                v = hex(v)
                v = v.replace("0x", "")
                v = v.zfill(2)
                v = v.rjust(4)
            else:
                v = "  --"
            print(v, end=" ")
        print()
    print()


def print256dec(arr):
    print()
    for pil in range(16):
        for pir in range(16):
            v = arr[pil*16+pir]
            if v >= 0:
                v = str(v).rjust(4)
                v = " " + v
            else:
                v = "   --"
            print(v, end=" ")
        print()
    print()


targetstr = "Hire me!!!!!!!!"
target16 = [0]*16
for i in range(15):
    char = targetstr[i:i+1]
    target16[i] = ord(char)



# generate good byte pairs for target
debug_goodpairs = 0

goodpairs = {}
for n in range(16):
    print("target16[" + str(n) + "]=", geth(target16[n]), chr(target16[n]))
    pairs = []
    notfound_byte1_cnt = 0
    all_found_pairs = 0
    for byte1 in range(256):
        found_cnt = 0
        for byte2 in range(256):
            if arr512[byte1] ^ arr512[256+byte2] == target16[n]:
                found_cnt += 1
                all_found_pairs += 1
                if debug_goodpairs:
                    print("byte1 byte2 ", geth(byte1)+geth(byte2), "found_cnt",found_cnt)
                pairs.append([byte1, byte2])
        if not found_cnt:
            notfound_byte1_cnt += 1
            if debug_goodpairs:
                print("b1+2NOTFOUND", geth(byte1))
    if debug_goodpairs:
        print("notfound_byte1_cnt", notfound_byte1_cnt)
        print("all_found_pairs", all_found_pairs)
    goodpairs[n] = pairs
print()

print("goodpairs[0] =")
for p in goodpairs[0]:
    print(p)
print("len(goodpairs[0]) =", len(goodpairs[0]))
print()

print("goodpairs")
for r in range(256):
    rstr = ""
    for c in range(16):
        gp = goodpairs[c][r]
        rstr += th(gp[0]) + th(gp[1]) + "  "
    print(rstr)
print()

print("try to assemble target from good bytes indexes")
testx = [4, 1, 0, 0, 0, 0, 3, 0, 4, 0, 0, 0, 0, 2, 0, 0]
for n in range(16):
    pair = goodpairs[n][testx[n]]
    char = arr512[pair[0]] ^ arr512[256+pair[1]]
    print(chr(char), end="")
print()


for i in range(16):
    testx[i] = random.randrange(256)
for n in range(16):
    pair = goodpairs[n][testx[n]]
    char = arr512[pair[0]] ^ arr512[256+pair[1]]
    print(chr(char), end="")
print()


print()



print("xorbits")
print()
for i in range(32):
    xorstr = ""
    for n in range(32):
        if arr32[i] & (2**n) > 0:
            xorstr += "1"
        else:
            xorstr += "0"
    print(xorstr)
print()

print("xorbits")
print()
for i in range(32):
    xorstr = ""
    for n in range(32):
        if arr32[i] & (2**n) > 0:
            xorstr += "XX"
        else:
            xorstr += "  "
    print(xorstr)
print()

xorlist = {}
for i in range(32):
    nlist = []
    for n in range(32):
        if i == n:
            continue
        if arr32[i] & (2**n) > 0:
            nlist.append(n)
    xorlist[i] = nlist

print("xorlist")
print()
for i in range(32):
    print(len(xorlist[i]), xorlist[i])
print()


after_xor_bytes = [0]*256
after_hash_bytes = [0]*256

for _ in range(10):
    input32 = [0]*32
    for i in range(32):
        v = random.randrange(256)
        input32[i] = v

    iterationcount = 256
    for _ in range(iterationcount):
        for i in range(32):
            input32[i] = arr512 [ input32[i] ]

        for i in range(32):
            after_hash_bytes[ input32[i] ] += 1

        xoroutput32 = [0]*32
        for i in range(32):
            for n in range(32):
                if arr32[i] & (2**n) > 0:
                    xoroutput32[i] ^= input32[n]

        for i in range(32):
            after_xor_bytes[ xoroutput32[i] ] += 1
        for i in range(32):
            input32[i] = xoroutput32[i]

print("after_hash_bytes")
print256dec(after_hash_bytes)
print("after_xor_bytes")
print256dec(after_xor_bytes)











exact_revarr = [-1]*256
touch_times = [0]*256
for i in range(256):
    v = i
    for _ in range(1000):
        prev = v
        v = arr512[v]
        touch_times[v] += 1
        if touch_times[v] > 20 and exact_revarr[v] == -1:
            exact_revarr[v] = prev
print("touch_times")
print256dec(touch_times)


c = 0
for i in range(256):
    if not exact_revarr[i] == -1:
        c += 1
print("exact_revarr count")
print(c)

print()
print("exact_revarr")
print256(exact_revarr)


rev1 = [-1]*256
rev2 = [-1]*256
for i in range(256):
    n = arr512[i]
    if not rev1[ n ] == -1:
        rev2[ n ] = i
    else:
        rev1[ n ] = i
banned1 = [0]*256
bannedbytescounter = 0
for i in range(256):
    if rev1[i] == -1:
        banned1[i] = 1
        bannedbytescounter += 1
print("rev1")
print256(rev1)
print("rev2")
print256(rev2)
print("banned1")
print256z(banned1)


self_revlens=[-1]*256
self_revlens_cnt = 0

for i in range(256):
    v = i
    pathmem = [0]*256
    pathmem[v] = 1
    pathlen = 1
    for _ in range(500):
        v = rev1[v]
        if pathmem[v] == 1:
            break
        pathlen += 1
    if pathlen < 256:
        self_revlens[i] = pathlen
        self_revlens_cnt += 1

print("self_revlens")
print256(self_revlens)
print("self_revlens_cnt")
print(self_revlens_cnt)
print()



