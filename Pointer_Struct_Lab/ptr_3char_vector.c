/*
Given vector.h and vector.c from the Vector ADT section of the book, modify the code so that the vector holds characters instead of integers. Define also the following 
new functions in vector.c :

    1. void vector_from_string(vector* v, char* string) - Create vector v then copy the characters from string to v.
    2. void vector_print(vector* v) - Print vector v as a string; do not end with a newline

The result will implement a string that is more flexible than the standard C char* strings. In particular insertion and deletion of characters are allowed anywhere in 
the strings.

The main program performs various actions to test the new vector. Complete main() by replacing each TODO comment with code that implements the described actions.

Note: Some operations in main() occur in pairs. After the program performs the first operation, the second operation is applied to the result of the first operation, 
rather than the state of the vector before performing the first operation.

Ex:

vector = friend
Input indices for removal: a = 1 b = 2
    friend -- removing character at index 1 --> fiend
    fiend -- removing character at index 2 --> find

Ex: If the input is:

ridge
y
0 3
0 e 1 r
1 n 2 e

the output is:

ridge
ridgey
idgy
ergy
energy
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
//#include "vector.h"

// struct and typedef declaration for Vector ADT
typedef struct vector_struct {
    //int* elements;
    char* elements;
    unsigned int size;
} vector;

// interface for accessing Vector ADT

// Initialize vector
void vector_create(vector* v, unsigned int vectorSize);

// Destroy vector
void vector_destroy(vector* v);

// Resize the size of the vector
void vector_resize(vector* v, unsigned int vectorSize);

// Return pointer to element at specified index
char* vector_at(vector* v, unsigned int index);

// Insert new value at specified index
void vector_insert(vector* v, unsigned int index, char value);

// Insert new value at end of vector
void vector_push_back(vector* v, char value);

// Erase (remove) value at specified index
void vector_erase(vector* v, unsigned int index);

// Return number of elements within vector
int vector_size(vector* v);

// Convert an ordinary string to a vector
void vector_from_string(vector*, char* string);

// Print the vector as if it were a string
void vector_print(vector* v);

int main(void) {
    int a;
    int b;
    char char1;
    char char2;
    vector v;
    char string[50];

    // Read a string
    scanf("%s\n", string);

    // TODO: Create a vector from the input string
    vector_from_string(&v, string);
    vector_print(&v);
    printf("\n");

    // Read a character char1
    scanf("%c", &char1);

    // TODDO: Add char1 to the end of the string
    vector_push_back (&v, char1);
    vector_print(&v);
    printf("\n");

    // Read two indices a and b
    scanf("%d %d", &a, &b);

    // TODO: Remove the character at index a from the vector,
    vector_erase(&v, a);
    // then remove the character at index b of the modified vector
    vector_erase(&v, b);
    vector_print(&v);
    printf("\n");

    // Read two pairs of index and character
    scanf("%d %c %d %c", &a, &char1, &b, &char2);

    // TODO: Replace the character at index a with char1 and
    vector_erase(&v, a);
    vector_insert(&v, a, char1);
    // the character at index b with char2
    vector_erase(&v, b);
    vector_insert(&v, b, char2);
    vector_print(&v);
    printf("\n");

    // Read two pairs of index and character
    scanf("%d %c %d %c", &a, &char1, &b, &char2);

    // TODO: Insert character char1 before index a of the vector, then
    vector_insert(&v, a, char1);
    // insert character char2 before index b of the modified vector
    vector_insert(&v, b, char2);
    vector_print(&v);
    printf("\n");

    // TODO: Free the memory allocated to the vectort
    free(v.elements);
    return 0;
}


// Initialize vector with specified size
void vector_create(vector* v, unsigned int vectorSize) {
    int i;

    if (v == NULL) return;

    v->elements = (char*)malloc(vectorSize * sizeof(char));;
    v->size = vectorSize;
    for (i = 0; i < v->size; ++i) {
        v->elements[i] = 0;
    }
}

// Destroy vector
void vector_destroy(vector* v) {
    if (v == NULL) return;

    free(v->elements);
    v->elements = NULL;
    v->size = 0;
}

// Resize the size of the vector
void vector_resize(vector* v, unsigned int vectorSize) {
    int oldSize;
    int i;

    if (v == NULL) return;

    oldSize = v->size;
    v->elements = (char*)realloc(v->elements, vectorSize * sizeof(char));
    v->size = vectorSize;
    for (i = oldSize; i < v->size; ++i) {
        v->elements[i] = 0;
    }
}

// Return pointer to element at specified index
char* vector_at(vector* v, unsigned int index) {
    if (v == NULL || index >= v->size) return NULL;

    return &(v->elements[index]);
}

// Insert new value at specified index
void vector_insert(vector* v, unsigned int index, char value) {
    int i;

    if (v == NULL || index > v->size) return;

    vector_resize(v, v->size + 1);
    for (i = v->size - 1; i > index; --i) {
        v->elements[i] = v->elements[i-1];
    }
    v->elements[index] = value;
}

// Insert new value at end of vector
void vector_push_back(vector* v, char value) {
    vector_insert(v, v->size, value);
}

// Erase (remove) value at specified index
void vector_erase(vector* v, unsigned int index) {
    int i;

    if (v == NULL || index >= v->size) return;

    for (i = index; i < v->size - 1; ++i) {
        v->elements[i] = v->elements[i+1];
    }
    vector_resize(v, v->size - 1);
}

// Return number of elements within vector
int vector_size(vector* v) {
    if (v == NULL) return -1;

    return v->size;
}

// Convert an ordinary string to a vector
void vector_from_string(vector* v, char* string) {
    vector_create(v, strlen(string));
    /* Type your code here. */
    for (int i = 0; i < strlen(string); i++)
    {
        vector_erase(v, i);
        vector_insert(v, i, string[i]);
    }
}

// Print the elements of the vector (no final newline)
void vector_print(vector* v) {

    /* Type your code here. */
    for (int i = 0; i < v->size; i++)
    {
        printf("%c", v->elements[i]);
    }
}
