//Sources:
//1: https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm

#include <stdio.h>
#include <stdlib.h>

// sources used: 1
struct node {
    char* line;
    int key;
    struct node *next;
};

char* readFile(char* inputfile) {
    FILE* f;
    char *buf;
    size_t length = 0;
    if ((f = fopen(inputfile, "r")) == NULL) {
        puts("File can't be opened.");
        exit(1);
    }
    while (getline(&buf, &length, f) != -1) {
        printf("%s", buf);    
    }
    printf("\n");
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
        readFile(argv[1]);
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