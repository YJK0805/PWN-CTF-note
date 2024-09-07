all: ./src
	gcc ./src/bof.c -o ./bof/share/bof -fno-stack-protector
	gcc src/ret2code.c -o ./ret2code/share/ret2code -fno-stack-protector -no-pie
clean:
	rm ./bof/share/bof
	rm ./ret2code/share/ret2code
