
# dohash = { 0:[3, "rnd", "n_findmaxres.c"], 1:[3, "fix", "n_findmaxres.c"] }
dohash = { 0:[10, "rnd", "n_findmaxres.c"] }

import random
import os

runsdir = "runs\\"
if not os.path.exists(runsdir):
    os.makedirs(runsdir)

bf = open(runsdir + "_compile.bat", "w")
rf = open(runsdir + "_run.bat", "w")

for dokey in sorted(dohash.keys()):
    genruns = dohash[dokey][0]
    genmode = dohash[dokey][1]
    srcfile = dohash[dokey][2]

    allcfiles = []

    rewritedefs = ["START_TRY_LO64", "START_TRY_HI64", "RANDOM_SEEDVAL"]
    for currun in range(genruns):

        sf = open(srcfile, "r")

        ofilename = srcfile.replace(".c", "_" + genmode + "_" + str(currun) + ".c")
        allcfiles.append(ofilename)
        of = open(runsdir + ofilename, "w")

        for line in sf:

            if "n_data.inc" in line:
                of.write(line.replace("n_data.inc", "..\\n_data.inc"))
                continue

            if "n_misc.inc" in line:
                of.write(line.replace("n_misc.inc", "..\\n_misc.inc"))
                continue

            if "n_xor.inc" in line:
                of.write(line.replace("n_xor.inc", "..\\n_xor.inc"))
                continue

            if "#define" in line:
                if "USE_RANDOM_TRY" in line:
                    if genmode == "rnd":
                        of.write("#define USE_RANDOM_TRY\t\t1\n")
                    else:
                        of.write("#define USE_RANDOM_TRY\t\t0\n")
                    continue

                if "RESULTFILENAME" in line:
                    newline = line.replace(".bin", "_" + genmode + "_" + str(currun) + ".bin")
                    of.write(newline)
                    continue

                writedone = 0
                for newval in rewritedefs:
                    if line.find(newval) > 0:
                        hexval = "0x"
                        if genmode == "rnd":
                            for i in range(16):
                                v = random.randrange(16)
                                v = hex(v)[2:]
                                hexval += v
                        else:
                            for i in range(4):
                                if currun == 0:
                                    hexval += "0000"
                                else:
                                    v = random.randrange(16)
                                    v = hex(v)[2:]
                                    hexval += v + "0" + v + "0"
                        of.write("#define " + newval + "\t\t" + hexval + "\n")
                        writedone = 1
                        break
                if writedone:
                    continue

            of.write(line)
        sf.close()
        of.close()


    for cfile in allcfiles:
        cfilename = cfile.replace(".c", "")
        exefilename = cfilename + ".exe"
        bf.write("gcc -o " + cfilename + " -O3 " + cfile + "\n")
        rf.write("start " + exefilename + "\n")
        rf.write("sleep.py 0.2\n")

bf.close()
rf.close()
