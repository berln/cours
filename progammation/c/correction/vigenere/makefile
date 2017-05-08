all: code decode

code: src/vigenere.c src/vigenere.h
	gcc src/vigenere.c -o bin/code

decode: bin/code
	cp bin/code bin/decode

clean:
	rm -f bin/* 

