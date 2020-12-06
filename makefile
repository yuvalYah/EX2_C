CC=gcc
AR=ar
FLAGS=-Wall -g -Wno-misleading-indentation

main: libmyBank.a main.o
	$(CC) $(FLAGS)  main.o libmyBank.a -o main
libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o 
main.o: main.c myBank.h  
	$(CC) $(FLAGS) -c main.c -o main.o
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c  -o myBank.o


clean:
	rm -f *.o *.a *.so mymaths mymathd
