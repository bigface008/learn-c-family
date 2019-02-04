objects = main.o utils.o

app : $(objects)
	gcc -o app $(objects)

main.o : main.c utils.h
	gcc -c -g main.c

utils.o : utils.c utils.h
	gcc -c -g utils.c

clean :
	rm app *.o
