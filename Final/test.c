// Ordered Doubly-LinkedList
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_struct {
    // String with length of 15
    char string[15];
    // Link to the next node
    struct Node_struct* nextNodePtr;
    // Link to the previous node
    struct Node_struct* prevNodePtr;
} Node;

// Two global pointer variables to keep the start and end of the list, initialized with NULL.
Node* start = NULL;
Node* end = NULL;

// Selection menu (This function has already been developed)
void menu(void);

/*************
* Develop this function at the bottom of this program
* Print the list.
*/
void printList();

/*************
* Develop this function at the bottom of this program
* Check if the list is empty.
*/
int isEmpty();

/*************
* Develop this function at the bottom of this program
* Set the node's data, using a string value.
*/
void setData(Node* node, char* value);

/*************
* Develop this function at the bottom of this program
* Insert a new node into the list in its correct location.
*/
void insert(Node* newPtr);

/*************
* Develop this function at the bottom of this program
* It receives a string to delete the very first node equal to it, if found.
* If found, it returns the string value of the deleted node, Otherwise, returns ""
(empty string).
*/
char* delete(char* value);

/*************
* Develop this function at the bottom of this program
* Print the list in the reverse order (from the end of the list to the beginning of
the list).
*/
void printListReverse();

/*************
* Read some words from an input file and insert them to the list.
*/
void readData();

/*************
* Write the list into an output file.
*/
void writeData();

/*************
* Develop this function at the bottom of this program
* Safely make a linked list empty.
*/
void emptyList();

// main function
int main(void) {
    Node* newPtr = NULL;
    char item[15];

    // Creating the starting/ending node.
    start = (Node*)malloc(sizeof(Node));
    setData(start, "#");
    end = start;
    puts("An empty ordered Doubly-LinkedList created.");
    puts("********************************************");
    menu();
    printf("%s", "? ");
    unsigned int choice; // user's choice
    scanf("%u", &choice);
    fflush(stdin);

    while (choice != 8) 
    {
        switch (choice) 
        {
            case 1:
            /*************
            * Complete this part:
            * 1- Prompt the user to input a character.
            * 2- Read the user's input.
            * 3- Insert the input character into the list.
            * 4- Print the linkedlist.
            */
            printf("%s", "Enter a name (Maximum 14 characters): ");
            fgets(item, 15, stdin);

            if (item[strlen(item) - 1] == '\n')
            {
                item[strlen(item) - 1] = '\0';
            }

            newPtr = (Node*)malloc(sizeof(Node)); // create node

            setData(newPtr, item);
            insert(newPtr); // insert item in list
            printList();
            break;

            case 2:
            /*************
            * Complete this part:
            * 1- If the list is empty, print out a proper message and skip this case.
            * Otherwise, prompt the user to input a string.
            * 2- Read the user's input.
            * 3- Delete the node that has the input string from the list,
            * and Print the linkedlist. If not found, show a proper message.
            */
            if (!isEmpty()) 
            {
                printf("%s", "Enter character to be deleted: ");
                fgets(item, 15, stdin);
                if (item[strlen(item) - 1] == '\n')
                {
                    item[strlen(item) - 1] = '\0';
                }

                char* found = delete(item);
                if (strcmp(found, "") != 0) 
                {
                    printf("%s deleted.\n", item);
                    printList();
                }
                else
                {
                    printf("%s not found.\n\n", item);
                }
            }
            else
            puts("List is empty.\n");
            break;

            case 3:
            /*************
            * Complete this part:
            * 1- If the list is empty, print out a proper message,
            * Otherwise, print the linkedlist from the BEGINNING of the list.
            */
            if (!isEmpty())
            {
                printList();
            }
            else
            {
                puts("List is empty.\n");
            }
            break;

            case 4:
            /*************
            * Complete this part:
            * 1- If the list is empty, print out a proper message,
            * Otherwise, print the linkedlist from the END of the list.
            */
            if (!isEmpty())
            {
                printListReverse();
            }
            else
            {
                puts("List is empty.\n");
            }
            break;

            case 5:
            /*************
            * Complete this part:
            * Call the proper fnnction to read from an input file.
            */
            readData();
            break;

            case 6:
            /*************
            * Complete this part:
            * Call the proper fnnction to write the list into a file.
            */
            if (!isEmpty())
            {
                writeData();
            }
            else
            {
                puts("List is empty.\n");
            }
            break;

            // Handling invalid choice
            case 7:
            /*************
            * Complete this part:
            * Call the proper fnnction to empty the list.
            */
            if (!isEmpty())
            {
                emptyList();
            }
            puts("List is empty.\n");
            break;

            default:
            puts("Invalid choice.\n");
            break;
        } // end switch

        menu();
        printf("%s", "? ");
        scanf("%u", &choice);
        fflush(stdin);
    }
    puts("End of run.");
}
// Display the menu options.
void menu(void) 
{
    puts("Enter your choice:\n"
    " 1 to insert an element into the list.\n"
    " 2 to delete an element from the list.\n"
    " 3 to print the list from the beginning.\n"
    " 4 to print the list from the end.\n"
    " 5 Read some words from input file and insert them to the list.\n"
    " 6 Write the list into the output file.\n"
    " 7 Empty the list.\n"
    " 8 to end.");
}

// Print the list
void printList() 
{
    Node* current = start;
    printf("NULL <-->");
    while (current != NULL) 
    {
        printf(" %s <-->", current->string);
        current = current->nextNodePtr;
    }
    printf(" NULL");
    printf("\n");
}

// Return 1 if the list is empty, 0 otherwise
int isEmpty() 
{
    Node* current = start;
    current = current->nextNodePtr;
    return (strcmp(current->string, "") == 0);
}

/*************
* Develop function setData.
*/
void setData(Node* node, char* value) 
{
    strcpy (node->string, value);
    node->nextNodePtr = NULL;
    node->prevNodePtr = NULL;
}

/*************
* Develop function insert.
*/
void insert(Node* newPtr) 
{
    Node* current = start;
    Node* previous = NULL;

    //Loop until current Node is NULL or found a string that is the same or a string has higher alphabetical order than the 'newPtr' string
    while (current != NULL && strcmp(newPtr->string, current->string) > 0 && strcmp(current->string, "#") != 0) //if the first letter of the name of newPtr is > than than name of current (Dane > Carl in term of ASCII), continue the loop
    {
        previous = current;
        current = current->nextNodePtr;
    }

    //If the previous node is NULL and the start node is '#', replace it with newPtr
    if ((previous == NULL) && strcmp(current->string, "#") == 0)
    {
        start = newPtr;
    }
    //else if the previous is NULL but the next node has content in it
    else if (previous == NULL) 
    {
        newPtr->nextNodePtr = current;
        newPtr->prevNodePtr = NULL;
        current->prevNodePtr = newPtr;
        start = newPtr;
    } 
    //else, if the previous and next node of the 'newPtr' node has content, do the same as a normal DLL
    else 
    {
        newPtr->nextNodePtr = current;
        newPtr->prevNodePtr = previous;
        previous->nextNodePtr = newPtr;
        
        //if the current node is not NULL (not at the end of the node), assign the currentNode->previous to newPtr
        if (current != NULL) 
        {
            current->prevNodePtr = newPtr;
        } 
        //if the current node is NULL (End of the node), assign end to the newPtr
        else 
        {
            end = newPtr;
        }
    }
}

/*************
* Develop function delete.
*/
char* delete(char* value) 
{
    Node* current = start;

    //Loop though until the string is found or reach the end
    while (current != NULL && strcmp(value, current->string) != 0) 
    {
        current = current->nextNodePtr;
    }

    char *tempCurrent = (char*)malloc (strlen(current->string) * sizeof(char)); 
    strcpy(tempCurrent, current->string);

    //If reach the end, return empty string
    if (current == NULL) 
    {
        return "";
    }

    //If the previous node of current is NULL, then change the start node to current-> next
    if (current->prevNodePtr == NULL) 
    {
        start = current->nextNodePtr;
        start->prevNodePtr = NULL;
    } 
    //else do the same as delete node from DLL
    else 
    {
        current->prevNodePtr->nextNodePtr = current->nextNodePtr;
        if (current->nextNodePtr != NULL) 
        {
            current->nextNodePtr->prevNodePtr = current->prevNodePtr;
        }
        //if delete the final node, change the end node to current->previousNode
        else 
        {
            end = current->prevNodePtr;
        }
    }

    free(current);
    return tempCurrent;
}

/*************
* Develop function printListReverse.
*/
void printListReverse() 
{
    Node* current = end;

    printf("NULL <-->");
    while (current != NULL) 
    {
        printf("%s  <-->", current->string);
        current = current->prevNodePtr;
    }
    printf(" NULL");
    printf("\n");
}

/*************
* Develop function readData.
*/
void readData() 
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) 
    {
        printf("Could not open file\n");
        return;
    }

    Node* newPtr = NULL;
    char string[15];
    while (fscanf(file, "%14s", string) == 1) 
    {
        newPtr = (Node*)malloc(sizeof(Node));
        setData(newPtr, string);
        insert(newPtr);
    }

    fclose(file);
}

/*************
* Develop function writeData.
*/
void writeData() 
{
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) 
    {
        printf("Error opening output file");
        return;
    }

    Node* current = start;
    while (current != NULL) 
    {
        fprintf(file, "%s  ", current->string);
        current = current->nextNodePtr;
    }

    fclose(file);
}

/*************
* Develop function emptyList.
*/
void emptyList() 
{
   Node* current = start;
   Node* next;

   //Assign next to current-> nextNode then delete the current node, repeat until over
   while(current != NULL) 
   {
      next = current->nextNodePtr;
      free (current);
      current = next;
   }
   //Delete the start node
   start = NULL;
}