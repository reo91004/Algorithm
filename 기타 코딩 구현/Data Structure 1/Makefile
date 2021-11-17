CC=gcc
TARGET=a.out
OBJS=myString.o main.o
a.out : myString.o main.o
		gcc -o a.out myString.o main.o
    
    myString.o : myString.c
		gcc -c -o myString.o myString.c
    
    main.o : main.c
		gcc -c -o main.o main.c