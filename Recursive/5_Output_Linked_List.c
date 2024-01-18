#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode_struct {
   int dataVal;
   struct IntNode_struct* nextNodePtr;
} IntNode_struct;

/* TODO: Write recursive PrintLinkedList() function here. */
void PrintLinkedList(IntNode_struct* thisNode) 
{
    if (thisNode == NULL)
    {
        return;
    }
    else
    {
        IntNode_PrintData (thisNode);
        thisNode = IntNode_GetNext (thisNode);
        PrintLinkedList (thisNode);
    }
}

// Create a new node
IntNode_struct* CreateNode(int value) {
   IntNode_struct* newNode = (IntNode_struct*)malloc(sizeof(IntNode_struct));
   newNode->dataVal = value;
   newNode->nextNodePtr = NULL;

   return newNode;
}

// Insert a new node after the current node
void IntNode_InsertAfter (IntNode_struct* thisNode, IntNode_struct* newNode) {
   IntNode_struct* tmpNext = NULL;

   tmpNext = thisNode->nextNodePtr;  // Remember next
   thisNode->nextNodePtr = newNode;  // this -- new -- ?
   newNode->nextNodePtr = tmpNext;   // this -- new -- next
}

// Get location pointed by nextNodePtr
IntNode_struct* IntNode_GetNext(IntNode_struct* thisNode) {
   return thisNode->nextNodePtr;
}

// Print node's data
void IntNode_PrintData(IntNode_struct* thisNode) 
{
   printf("%d, ", thisNode->dataVal);
}

int main(void) {
   int size;
   int value;
   
   scanf("%d", &size);
   scanf("%d", &value);
   IntNode_struct* headNode = CreateNode(value); // Make head node as the first node
   IntNode_struct* lastNode = headNode;     // Node to add after
   IntNode_struct* newNode = NULL;          // Node to create

   // Insert the second and the rest of the nodes
   for (int n = 0; n < size - 1; ++n) 
   {
      scanf("%d", &value);
      newNode = CreateNode(value);
      IntNode_InsertAfter(lastNode, newNode);
      lastNode = newNode;
   }

   // Call PrintLinkedList with node after head node
   PrintLinkedList(headNode);
   return 0;
}