reverse: reverse.o
	gcc reverse.c -o reverse -Wall
clean:
	rm -rf *.o