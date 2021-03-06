from n_data import *

#Reverse me fast
input32 = [ 0x66,0xd5,0x4e,0x28,0x5f,0xff,0x6b,0x53,0xac,0x3b,0x34,0x14,0xb5,0x3c,0xb2,0xc6,0xa4,0x85,0x1e,0x0d,0x86,0xc7,0x4f,0xba,0x75,0x5e,0xcb,0xc3,0x6e,0x48,0x79,0x8f ]
iterationcount = 256
do_xor = 1

input32 = [ 0x00,0xa0,0x00,0xed,0x00,0x9a,0x00,0xdc,0x00,0xfb,0x00,0xf1,0x00,0xdc,0x00,0x13,0x00,0x13,0x00,0x13,0x00,0x13,0x00,0x13,0x00,0x13,0x00,0x13,0x00,0x13,0x00,0xa9 ]
iterationcount = 256
do_xor = 0

input32 = [
0x31,0xb7,0xf4,0x48,0x35,0x8f,0xd6,0x57,0x0,0x5e,0x7d,0xc,0xc5,0x2b,0xf,0xe7,0xf4,0xb3,0xdf,0xa9,0xf7,0x99,0xb5,0xb1,0xde,0xa7,0xdd,0xcf,0x5b,0x26,0x1d,0x16,
]
iterationcount = 256
do_xor = 1

print("input32\n")
for i in range(32): print(hex(input32[i]), end=",")
print("\n\niterationcount", iterationcount)
print("do_xor", do_xor)

for _ in range(iterationcount):
    for i in range(32):
        input32[i] = arr512[ input32[i] ]
    if do_xor:
        temp32 = input32[:]
        for i in range(32):
            for k in range(14):
                input32[i] ^= temp32[ xorlist[i][k] ]

outstr = ""
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
