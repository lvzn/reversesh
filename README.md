# reversesh
A little C program to read the lines you input and print them out in reverse order.

## List of features 
- read input from file and print to stdout (1 argument)
- read input from file and write output to file (2 arguments)
- read input from stdin and print output to stdout (0 arguments)

## Compiling and running
To compile the code just run `make` in the root of the folder in your shell.
After compilation, you should be able to run the program using `./reverse arg1 arg2`

## Usage
There are three ways to run the program: </br> </br>
`./reverse` </br>
in this case you will read input straigt from stdin. To stop, just type nothing and press enter. </br> </br>
`./reverse inputfile.txt` </br>
in this case you will provide the program with a file it will read the input from. The result will be printed in stdout. </br> </br>
`./reverse inputfile.txt outputfile.txt` </br>
in this case the text will be read from the file you provide in the first argument and will be written in the file you provide in the second.
