//Sources:
//1: https://www.geeksforgeeks.org/linked-list-set-1-introduction/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// sources used: 1
typedef struct node {
    char* line;
    int key;
    struct node* next;
}Node;

Node* addNode(Node* head, char* line);
Node* readFile(char* inputfile, Node* head);
void printLines(Node* head);
void writeLines(Node* head, char* filename);

//Reading lines from users' input if no args given
Node* readlines(Node* head) {
    char* buf;
    size_t length = 0;
    while (getline(&buf, &length, stdin) != -1) {
        if (strcmp(buf, "\n") == 0)
            break;
        head = addNode(head, buf);
    }
    return head;
}

//Reading file from first arg given
Node* readFile(char* inputfile, Node* head) {
    FILE* f;
    char* buf;
    size_t length = 0;
    if ((f = fopen(inputfile, "r")) == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", inputfile);
        exit(1);
    }
    while (getline(&buf, &length, f) != -1) {
        head = addNode(head, buf);
    }
    fclose(f);
    return head;
}

//Creates a new node and makes it point to the previous head node
Node* addNode(Node* head, char* line) {
    Node* newNode;
    //Dynamically allocating memory
    if ((newNode = malloc(sizeof(Node))) == NULL) {
        fprintf(stderr, "malloc failed");
        exit(1);
    }
    newNode->line = strdup(line);
    newNode->next = head;
    return newNode;
}

//Printing lines from the linked list
void printLines(Node* head) {
    while (head != NULL) {
        printf("%s", head->line);
        head = head->next;
    }
}

//Writing lines to the given file
void writeLines(Node* head, char* filename) {
    FILE* f = NULL;
    if ((f = fopen(filename, "w")) == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", filename);
        exit(1);
    }
    while (head != NULL) {
        fprintf(f, "%s", head->line);
        head = head->next;
    }
    fclose(f);
}

void freeMemory(Node* head) {
    Node *ptr = head;
    while (ptr != NULL) {
        head = ptr->next;
        free(ptr);
        ptr = head;
    }
}

int main(int argc, char** argv) {
    Node* head = NULL;

    switch (argc) {
    case 1:
        //Updating "head" with the most recent given value
        head = readlines(head);
        printLines(head);
        break;
    case 2:
        head = readFile(argv[1], head);
        printLines(head);
        break;
    case 3:
        if (strcmp(argv[1], argv[2]) == 0) {
            fprintf(stderr, "Input and output file must differ\n");
            exit(1);
        }
        head = readFile(argv[1], head);
        writeLines(head, argv[2]);
        break;
    default:
        fprintf(stderr, "Too many arguments\n");
        break;
    }
    freeMemory(head);
    return 0;
}