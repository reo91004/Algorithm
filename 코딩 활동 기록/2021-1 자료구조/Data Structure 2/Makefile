CC=gcc
TARGET=a.out
OBJS=dictree.o main.o
a.out : dictree.o main.o
		gcc -o a.out dictree.o main.o
    
    dictree.o : dictree.c
		gcc -c -o dictree.o dictree.c
    
    main.o : main.c
		gcc -c -o main.o main.c