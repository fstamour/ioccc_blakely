


all: a.exe


.PHONY:
test_main: main.exe
	main.exe

main.exe: main.cpp
	$(CXX) -o $@ $^
	
	
v3.c: v3.h
	
a.exe: ioccc-blakely4.c parser.c v3.c
	$(CC) -o $@ $^ -O3 -lm

a.gif: a.exe
	a.exe "xx*yy*" 32 > a.gif
	
.PHONY:
test_a: a.gif
	start a.gif