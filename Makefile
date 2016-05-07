CC=clang++
CFLAGS=-stdlib=libc++ -std=gnu++11

all: c1-1 size32 size64 bigOrLittle

size32: size.cpp
	${CC} ${CFLAGS} -m32 size.cpp -o size32

size64: size.cpp
	${CC} ${CFLAGS} -m64 size.cpp -o size64

c1-1: c1-1.cpp
	${CC} ${CFLAGS} c1-1.cpp -o c1-1

bigOrLittle : bigOrLittle.cpp
	${CC} ${CFLAGS} bigOrLittle.cpp -o bigOrLittle

clean:
	rm c1-1 size32 size64 bigOrLittle
