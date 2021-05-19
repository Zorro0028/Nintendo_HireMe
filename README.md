### my solution to Nintendo [HireMe challenge](https://www.nerd.nintendo.com/files/HireMe)   

my asm solution is fastest, 14 seconds for generating one million results.  

my python solution is smallest, only 30 lines of pure python, without external libs, with some pre-gen values, to output all possible results.  

### runtime till first 4512 results

n_reverse.asm  
runtime 0.046 seconds  

n_reverse.c  
runtime 0.062 seconds  

n_reverse_xor_unroll.py  
runtime 12.125 seconds  

n_reverse.py  
runtime 22.219 seconds  

n_reverse_no_recursion.py  
runtime 31.672 seconds  

n_reverse_30lines_firstbench.py  
runtime 8.672 seconds (till one first result)  

### runtime till one million (1_001_663) results
asm = runtime 14.046 seconds  
c   = runtime 14.609 seconds (with -O3 compiler option)  

### runtime till one billon (1_000_000_000) results
asm = runtime 13188 seconds (3 hours 39 minutes 48 seconds)  
this is ~75 results per millisecond.  
32_000_000_000 bytes, 32 GB of results.  
SHA256 hash of __n_res_asm.bin: ae590a18c7c4ec7f7bbe2deb162f4d2dff828af55a79778321ca33e94c511419  

### very interesting finding
After about 48 hours of multi-threading CPU searching using findruns.py together with n_findmaxres.c I found very interesting last 32 bytes!  
This block of last 32 bytes has 430281 different possible starting variants for the correct solution!  
430281!  
0x72,0x73,0x09,0x5e,0x6d,0x09,0xf0,0x69,0x92,0x14,0x35,0xbb,0x20,0x60,0xe5,0x4d,0xb1,0xab,0xf1,0x13,0xab,0xc8,0x69,0x0a,0x05,0x51,0x32,0xdc,0xc8,0x6e,0x1c,0x4e,  

That's mean that there is 430_281 different possible starting 32 bytes (u8 input[32]) that after 256 iterations will result in the same last 32 bytes above, that will result in target message.  
You can "expand" this 32 block using n_last32_expander.c or n_last32_expander_xu.py to see the results.  

For comparison, to get the first 1_000_000 results you only need 207 "good last 32" bytes. n_reverse_calcgoodlast32.c  
That means that the average good 32 last bytes will result in ~1_000_000/207. ~4831 results per one good last 32 bytes.  
I expected to find maybe 150000, maybe 200000 max results per one block of last 32 bytes, but the finding of 430281 was very impressive for me.  

### misc

both c and asm solutions are non-recursive.  

after re-optimization of assembler's xor unroll,  
my assembler code is finally runs faster than optimized gcc c compiler.  
my first asm version was slower than c.  
x86_64bit assembler code made for windows.  

asm version compiled in windows using [flat assembler](https://github.com/tgrysztar)  
c   version compiled in windows using [MSYS2 environment](https://www.msys2.org)  

### links to solutions from others 2021-05-12:
https://github.com/ayufan/nintendo-hire-me  
https://github.com/IamLupo/Nintendo-HireMe  
https://github.com/AntonioGE/Nintendo-HireMe-Solver  
https://github.com/anonbeat/nintendo_hireme  
https://github.com/rnbwdsh/nintendo_hireme  
https://github.com/EthanTheMaster/nintendo_nerd_solution  
https://github.com/lewisxy/hireme-challenge  
https://www.youtube.com/watch?v=thbZwi6WwIE  
https://www.youtube.com/watch?v=70_Cox0qLo8  
https://www.youtube.com/watch?v=A5uPVXDY8tU  

Greetz to all who did it.  

Zorro.  
