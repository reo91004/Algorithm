CC=gcc
TARGET=a.out
OBJS=graph.o main.o stack.o queue.o
a.out : graph.o main.o stack.o queue.o
		gcc -o a.out graph.o stack.o queue.o main.o
    
    graph.o : graph.c
		gcc -c -o graph.o graph.c

    stack.o : stack.c
		gcc -c -o stack.o stack.c

    queue.o : queue.c
		gcc -c -o queue.o queue.c
    
    main.o : main.c
		gcc -c -o main.o main.c