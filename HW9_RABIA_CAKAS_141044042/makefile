HEADERS2=	HW09_RABIA_CAKAS_141044042_DoubleList.h

all:	program

program.o:	HW09_RABIA_CAKAS_141044042_main.c $(HEADERS2)
	gcc -c HW09_RABIA_CAKAS_141044042_main.c -o HW09_RABIA_CAKAS_141044042_main.o

program:	program.o
	gcc HW09_RABIA_CAKAS_141044042_main.o -o main


run_doubly:
	./main
clean:
	
	-rm -f main.o
	-rm -f main
