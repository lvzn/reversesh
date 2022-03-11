#include <stdio.h>

char* readfile(char* input) {

    return "";
}

int main(int argc, char** argv) {
    switch (argc) {
    case 1:
        puts("1 arg");
        //read input from stdin and reverse it to stdout
        break;
    case 2:
        puts("2 args");
        //read input from file and output to stdout
        break;
    case 3: 
        puts("3 args");
        //read input from file and output to output file
        break;
    default:
        puts("Too many arguments");
        break;
    }
    return 0;
}