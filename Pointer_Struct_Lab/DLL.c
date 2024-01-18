#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode_struct {
   int dataVal;
   struct IntNode_struct* nextNodePtr;
   struct IntNode_struct* previousNodePtr;
} IntNode;

IntNode* headObj  = NULL; // Create intNode objects
IntNode* lastObj  = NULL;

// Constructor
void IntNode_Create(IntNode* thisNode, int dataInit, IntNode* nextLoc, IntNode* previousLoc) {
   thisNode->dataVal = dataInit;
   thisNode->nextNodePtr = nextLoc;
   thisNode->previousNodePtr = previousLoc;
}

void IntNode_InsertAfter(IntNode* thisNode, IntNode* newNode) {   
	newNode->nextNodePtr = thisNode->nextNodePtr;
   // If the new node is adding to the end of the linkedlist
	if (thisNode->nextNodePtr != NULL)
   {
		thisNode->nextNodePtr->previousNodePtr = newNode;
   }		
	newNode->previousNodePtr = thisNode;
	thisNode->nextNodePtr = newNode;
	// If the new node is adding to the end of the linkedlist, update the node lastObj
	if (newNode->nextNodePtr == NULL)
   {
      lastObj = newNode;
   }
}

void IntNode_InsertBefore(IntNode* thisNode, IntNode* newNode) {   
	// Practice for the next session by you
	if (thisNode->previousNodePtr != NULL) //If this node previous node is not Null, we could assign the this.prev.next to the new node
   {
		thisNode->previousNodePtr->nextNodePtr = newNode;
   }		
   newNode->previousNodePtr = thisNode->previousNodePtr;
	newNode->nextNodePtr = thisNode;
	thisNode->previousNodePtr = newNode;
   if (newNode != NULL) //if new node is not NULL which mean the headObj is the new node
   {
      headObj = newNode;
   }
}

void IntNode_Delete(IntNode* thisNode) {
	thisNode->previousNodePtr->nextNodePtr = thisNode->nextNodePtr;
	thisNode->nextNodePtr->previousNodePtr = thisNode->previousNodePtr;
	free(thisNode); //remember to free or we will have memory leak from the heap
}

// Print dataVal
void IntNode_PrintNodeData(IntNode* thisNode) {
   printf("%d\n", thisNode->dataVal);
}

// Grab location pointed by nextNodePtr
IntNode* IntNode_GetNext(IntNode* thisNode) {
   return thisNode->nextNodePtr;
}

// Grab location pointed by previousNodePtr
IntNode* IntNode_GetPrevious(IntNode* thisNode) {
   return thisNode->previousNodePtr;
}

void IntNode_Clear(IntNode* firstNode)
{
   //clear the list completely
   IntNode* currentNode = firstNode;
   IntNode* nextNode;
   while(currentNode != NULL) 
   {
      nextNode = currentNode->nextNodePtr;
      free (currentNode);
      currentNode = nextNode;
   }
   firstNode = NULL;
}

int main(void) {
   IntNode* currObj  = NULL;
   int i;                    // Loop index

   // Create the very first node with the name headObj and lastObj
   headObj = (IntNode*)malloc(sizeof(IntNode)); // Front of nodes list
   IntNode_Create(headObj, -1, NULL,NULL);
   lastObj = headObj;
     
   // Create and insert a new node after headObj
   currObj = (IntNode*)malloc(sizeof(IntNode)); // Allocate memory for the new node
   IntNode_Create(currObj, 8, NULL,NULL);
   IntNode_InsertAfter(headObj,currObj);

   // Create and insert a new node after headObj
   currObj = (IntNode*)malloc(sizeof(IntNode)); // Allocate memory for the new node
   IntNode_Create(currObj, 5, NULL,NULL);
   IntNode_InsertAfter(headObj,currObj);

   // Create and insert a new node after lastObj
   currObj = (IntNode*)malloc(sizeof(IntNode)); // Allocate memory for the new node
   IntNode_Create(currObj, 11, NULL,NULL);
   IntNode_InsertAfter(lastObj,currObj);

   currObj = headObj;                           // Print the list from the head node
   while (currObj != NULL) {
      IntNode_PrintNodeData(currObj);
      currObj = IntNode_GetNext(currObj);
   }
  
   currObj = lastObj;                           // Print the list from the last node
   while (currObj != NULL) {
      IntNode_PrintNodeData(currObj);
      currObj = IntNode_GetPrevious(currObj);
   }

   currObj = headObj->nextNodePtr;
   IntNode_Delete(currObj);

   currObj = headObj;                           // Print the list from the head node. 
   while (currObj != NULL) {
      IntNode_PrintNodeData(currObj);
      currObj = IntNode_GetNext(currObj);
   }


   IntNode_Clear(headObj);

   return 0;
}