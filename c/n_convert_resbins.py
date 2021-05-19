import sys
import os

allbinfiles = []

alllines = 0

if len(sys.argv) == 2:
    binfilename = sys.argv[1]
    allfiles = 0
    allbinfiles.append(binfilename)
else:
    allfiles = 1
    with os.scandir(".") as it:
        for entry in it:
                if ".bin" in entry.name:
                    allbinfiles.append(entry.name)

last32hash = {}

bf = open("_allbin.bat", "w")
firstbf = 1

for binfilename in allbinfiles:
    if firstbf:
        bf.write("copy /b " + binfilename)
        firstbf = 0
    else:
        bf.write(" +" + binfilename)

    f = open(binfilename, "rb")

    f.seek(0, os.SEEK_END)
    fsize = f.tell()
    lines = fsize // (32+16)
    print(str(lines) + "\t" + binfilename)

    alllines += lines

    seek = 0
    while lines > 0:
        lines -= 1
        f.seek(seek)
        n = int.from_bytes(f.read(4), "little")
        seek += 16
        f.seek(seek)
        seek += 32
        last32 = [0]*32
        for i in range(32):
            last32[i] = int.from_bytes(f.read(1), "little")

        while n in last32hash.keys():
            print("key already exists", n)
            n += 1

        if last32 in last32hash.values():
            print("SAME LAST32!!!")

        last32hash[n] = last32

    f.close()

if allfiles:
    outfile = open("_all.py", "w")
    outfilec = open("_all.c", "w")
else:
    outfile = open(binfilename.replace(".bin", ".py"), "w")
    outfilec = open(binfilename.replace(".bin", ".c"), "w")

for last32key in sorted(last32hash.keys()):
    last32 = last32hash[last32key]
    outfile.write("# " + str(last32key) + "\n")
    outfile.write("last32 = [\n")
    outfilec.write("// " + str(last32key) + "\n")
    outfilec.write("unsigned char last32[32] = {\n");
    for i in range(32):
        v = last32hash[last32key][i]
        outfile.write("0x" + hex(v)[2:].zfill(2) + ",")
        outfilec.write("0x" + hex(v)[2:].zfill(2) + ",")
    outfile.write("\n]\n\n")
    outfilec.write("\n};\n\n")

outfile.close()
outfilec.close()

bf.write(" _all.allbin")
bf.close()

print("alllines", alllines)
