EXECS=hello hello_pi hello_md5
MPICC?=mpicc
MPICXX?=mpic++

all: ${EXECS}

hello: hello.c
	${MPICC} -o hello hello.c

hello_pi: hello_pi.c
	${MPICC} -o hello_pi hello_pi.c

hello_md5: hello_md5.cpp
	${MPICXX} -o hello_md5 hello_md5.cpp -lcrypto

clean:
	rm -f ${EXECS}
