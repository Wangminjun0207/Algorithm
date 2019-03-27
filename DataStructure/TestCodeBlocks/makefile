objects = main.o sort.o reverse.o display.o create.o
main:$(objects)
	gcc $(objects) -o main
main.o:main.c predefine.h
	gcc -c main.c -o main.o
sort.o:sort.c predefine.h
	gcc -c sort.c -o sort.o
reverse.o:reverse.c predefine.h
	gcc -c reverse.c -o reverse.o
display.o:display.c predefine.h
	gcc -c display.c -o display.o
create.o:create.c predefine.h
	gcc -c create.c -o create.o
clean:
	rm *.o main
