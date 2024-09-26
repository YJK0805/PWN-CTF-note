all: src/bof.c src/ret2code.c src/got.c src/ret2sc.c src/rop.c src/ret2libc.c src/ret2libc_adv.c src/ret2plt.c src/ret2plt_adv.c src/stack_pivoting.c
	gcc src/bof.c -o ./bof/share/bof -fno-stack-protector
	gcc src/ret2code.c -o ./ret2code/share/ret2code -fno-stack-protector -no-pie
	gcc src/got.c -o ./got/share/got -fno-stack-protector -no-pie
	gcc src/ret2sc.c -o ./ret2sc/share/ret2sc -fno-stack-protector -no-pie
	gcc src/rop.c -o ./rop/share/rop -fno-stack-protector -no-pie -static
	gcc src/ret2libc.c -o ./ret2libc/share/ret2libc -fno-stack-protector
	gcc src/ret2libc_adv.c -o ./ret2libc_adv/share/ret2libc_adv -fno-stack-protector
	gcc src/ret2plt.c -o ./ret2plt/share/ret2plt -fno-stack-protector -no-pie
	gcc src/ret2plt_adv.c -o ./ret2plt_adv/share/ret2plt_adv -fno-stack-protector -no-pie
	gcc src/stack_pivoting.c  -o ./stack_pivoting/share/stack_pivoting -fno-stack-protector -no-pie -static
clean:
	rm ./bof/share/bof
	rm ./ret2code/share/ret2code
	rm ./got/share/got
	rm ./ret2sc/share/ret2sc
	rm ./rop/share/rop
	rm ./ret2libc/share/ret2libc
	rm ./ret2libc_adv/share/ret2libc_adv
	rm ./ret2plt/share/ret2plt
	rm ./ret2plt_adv/share/ret2plt_adv
	rm ./stack_pivoting/share/stack_pivoting
