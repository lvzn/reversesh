reverse: reverse.o
	gcc reverse.o -o reverse
reverse.o: reverse.c
	gcc -c -Wall reverse.c 
clean:
	rm -rf *.o