all:
	gcc -o cli_engine.o -c cli_engine.c
	gcc -o func.o -c func.c
	gcc -o a.out main.c cli_engine.o func.o
clear:
	rm -f *.o 
	rm -f *.out