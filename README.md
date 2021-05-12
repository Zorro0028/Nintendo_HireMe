## my solution to Nintendo's HireMe.c challenge  
https://www.nerd.nintendo.com/files/HireMe

my asm solution is fastest, 14.7 seconds for generating one million results.  

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
runtime 8.672 seconds  

### runtime till one million (1_001_663) results
asm = runtime 14.735 seconds  
c   = runtime 15.500 seconds (with -O3 compiler option)  

after re-optimization of assembler's xor unroll,  
my assembler code is finally runs faster than optimized gcc c compiler.  
my first asm version was slower than c.  
x86_64bit assembler code made for windows.  

asm version compiled in windows using [flat assembler](https://github.com/tgrysztar)  
c   version compiled in windows using [MSYS2 environment](https://www.msys2.org)  

### links to solutions from others 2021-05-13:
https://github.com/ayufan/nintendo-hire-me  
https://github.com/IamLupo/Nintendo-HireMe  
https://github.com/AntonioGE/Nintendo-HireMe-Solver  
https://github.com/anonbeat/nintendo_hireme  
https://github.com/rnbwdsh/nintendo_hireme  
https://github.com/EthanTheMaster/nintendo_nerd_solution  
https://github.com/lewisxy/hireme-challenge  

greetz to all who did it.  

Zorro.  
