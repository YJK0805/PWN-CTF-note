all: ./src
	gcc ./src/bof.c -o ./bof/share/bof -fno-stack-protector
	gcc ./src/ret2code.c -o ./ret2code/share/ret2code -fno-stack-protector -no-pie
	gcc src/got.c -o ./got/share/got -fno-stack-protector -no-pie
	gcc src/orw.c -o ./orw/share/orw -fno-stack-protector -no-pie
	gcc src/rop.c -o ./rop/share/rop -fno-stack-protector -no-pie --static
clean:
	rm ./bof/share/bof
	rm ./ret2code/share/ret2code
	rm ./got/share/got
	rm ./orw/share/orw
	rm ./rop/share/rop
