all: hello evil_hello
hello: hello.c
	gcc -g -o hello hello.c

evil_hello: evil_hello.c
	gcc -g -no-pie -fno-stack-protector -z execstack -no-pie -o evil_hello evil_hello.c

find_offset: find_offset.c
	gcc -g -o find_offset find_offset.c

exploit: exploit.c
	gcc -g -o exploit exploit.c

clean:
	rm -f ./hello ./evil_hello ./find_offset ./*.

