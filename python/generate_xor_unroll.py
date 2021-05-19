outfile = open("__xor_unroll", "w")

from n_data import *

for i in range(32):
    outfile.write("    a = temp32[" + str(i) + "]\n")
    for k in range(14):
        outfile.write("    a ^= list32[" + str(xorlist[i][k]) + "]\n")
    outfile.write("    if banned[a]:\n")
    outfile.write("        return\n")
    outfile.write("    temp32[" + str(i) + "] = a\n")

outfile.close()
