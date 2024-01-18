#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_struct {
    char string[15];
    struct Node_struct* nextNodePtr;
    struct Node_struct* prevNodePtr;
} Node;

Node* start = NULL;
Node* end = NULL;

void menu(void);
void printList();
int isEmpty();
void setData(Node* node, char* value);
void insert(Node* newPtr);
char* delete(char* value);
void printListReverse();
void readData();
void writeData();
void emptyList();

int main(void) {
    // ... (unchanged)

    while (choice != 8) {
        switch (choice) {
            case 1:
                // ... (unchanged)
                break;

            case 2:
                // ... (unchanged)
                break;

            case 3:
                if (!isEmpty())
                    printList();
                else
                    puts("List is empty.\n");
                break;

            case 4:
                if (!isEmpty())
                    printListReverse();
                else
                    puts("List is empty.\n");
                break;

            case 5:
                readData();
                break;

            case 6:
                if (!isEmpty())
                    writeData();
                else
                    puts("List is empty.\n");
                break;

            case 7:
                if (!isEmpty())
                    emptyList();
                puts("List is empty.\n");
                break;

            default:
                puts("Invalid choice.\n");
                break;
        }

        menu();
        printf("%s", "? ");
        scanf("%u", &choice);
        fflush(stdin);
    }

    puts("End of run.");
}

// ... (unchanged)

void printList() {
    Node* currentPtr = start;

    while (currentPtr != NULL) {
        printf("%s ", currentPtr->string);
        currentPtr = currentPtr->nextNodePtr;
    }

    printf("\n");
}

int isEmpty() {
    return start == NULL;
}

void insert(Node* newPtr) {
    Node* current = start;
    Node* previous = NULL;

    while (current != NULL && strcmp(newPtr->string, current->string) > 0 && strcmp(current->string, "#") != 0) //if the first letter of the name of newPtr is > than than name of current (Dane > Carl in term of ASCII), continue the loop
    {
        previous = current;
        current = current->nextNodePtr;
    }

    if (previous == NULL) 
    {
        //newPtr->nextNodePtr = start;
        //newPtr->prevNodePtr = NULL;
        //start->prevNodePtr = newPtr;
        start = newPtr;
    } 
    else 
    {
        previous->nextNodePtr = newPtr;
        newPtr->prevNodePtr = previous;
        newPtr->nextNodePtr = current;

        if (current != NULL) 
        {
            current->prevNodePtr = newPtr;
        } 
        else 
        {
            end = newPtr;
        }
    }
}

char* delete(char* value) {
    Node* current = start;

    while (current != NULL && strcmp(value, current->string) != 0) {
        current = current->nextNodePtr;
    }

    if (current == NULL) {
        return "";
    }

    if (current->prevNodePtr == NULL) {
        start = current->nextNodePtr;
        if (start != NULL) {
            start->prevNodePtr = NULL;
        }
    } else {
        current->prevNodePtr->nextNodePtr = current->nextNodePtr;
        if (current->nextNodePtr != NULL) {
            current->nextNodePtr->prevNodePtr = current->prevNodePtr;
        } else {
            end = current->prevNodePtr;
        }
    }

    return current->string;
}

void printListReverse() {
    Node* currentPtr = end;

    while (currentPtr != NULL) {
        printf("%s ", currentPtr->string);
        currentPtr = currentPtr->prevNodePtr;
    }

    printf("\n");
}

void readData() {
    char item[15];
    FILE* inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        perror("Error opening input file");
        return;
    }

    while (fscanf(inputFile, "%14s", item) == 1) {
        Node* newPtr = (Node*)malloc(sizeof(Node));
        setData(newPtr, item);
        insert(newPtr);
    }

    fclose(inputFile);
}

void writeData() {
    FILE* outputFile = fopen("output.txt", "w");

    if (outputFile == NULL) {
        perror("Error opening output file");
        return;
    }

    Node* currentPtr = start;

    while (currentPtr != NULL) {
        fprintf(outputFile, "%s ", currentPtr->string);
        currentPtr = currentPtr->nextNodePtr;
    }

    fprintf(outputFile, "\n");
    fclose(outputFile);
}

void emptyList() {
    Node* currentPtr = start;
    Node* tempPtr;

    while (currentPtr != NULL) {
        tempPtr = currentPtr;
        currentPtr = currentPtr->nextNodePtr;
        free(tempPtr);
    }

    start = end = NULL;
}
