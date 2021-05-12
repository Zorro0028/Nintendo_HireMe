outputfilename = "____test_output.txt"

from __n_res_py import *
# from __n_res_py_xor_unroll import *
# from __n_res_py_no_recursion import *
from n_data import *

cnt = 0
last32 = []
first_input32_hashes = []
iterationcount = 256
do_xor = 1
print("iterationcount", iterationcount)
print("do_xor", do_xor)

outfile = open(outputfilename, "w")

for input32 in res.values():

    p = 31
    m = 1000000009
    p_pow = 1
    curhash = 0
    for i in range(32):
        v = input32[i]
        curhash = (curhash + (v+1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    if not curhash in first_input32_hashes:
        first_input32_hashes.append(curhash)
    else:
        print("SAME HASH FOUND")
        outfile.write("SAME HASH FOUND\n")
        outs = ""
        for n in input32:
            outs += "0x" + geth(n) + ","
        outs = outs.rstrip(",")
        samehash = "[ " + outs + " ]"
        print(samehash)
        outfile.write(samehash + "\n")
        # exit()

    for _ in range(iterationcount):
    
        for i in range(32):
            input32[i] = arr512[ input32[i] ]

        if do_xor:
            temp32 = input32[:]
            for i in range(32):
                for k in range(14): input32[i] ^= temp32[ xorlist[i][k] ]

    if not last32 == input32:
        last32 = input32
        print("last32 =", last32)
        outfile.write("last32 = " + str(last32) + "\n")

    cnt += 1
    outstr = str(cnt).ljust(8)

    result16 = [0]*16
    for i in range(16):
        byte1 = input32[i*2]
        byte2 = input32[i*2+1]
        v1 = arr512[byte1]
        v2 = arr512[256+byte2]
        r = v1 ^ v2
        result16[i] = r
    for i in range(16):
        byteval = result16[i]
        if byteval>=0x21 and byteval<=0x7e:
            outstr += chr(byteval)
        else:
            outstr += " "
    print(outstr)
    outfile.write(outstr + "\n")

    for i in range(16):
        if result16[i] != target16[i]:
            print("WRONG RESULT")
            outfile.write("WRONG RESULT\n")
            exit()
