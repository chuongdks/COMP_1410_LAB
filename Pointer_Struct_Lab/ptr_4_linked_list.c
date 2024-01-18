/*
Given an IntNode struct and the operating functions for a linked list, complete the following functions to extend the functionality of the linked list:

   1. IntNode* IntNode_GetNth(IntNode* firstNode, int n)- Return a pointer to the nth node of the list starting at firstNode.
   2. void IntNode_PrintList(IntNode* firstNode) - Call IntNode_PrintNodeData() to output values of the list starting at firstNode. Do not add extra space characters in between values.
   3. int IntNode_SumList(IntNode* firstNode) - Return the sum of the values of all nodes starting at firstNode.

Note: The code for IntNode_Create() provided here differs from the code shown in the book.

The given main() performs various actions to test IntNode_GetNth(), IntNode_PrintList(), and IntNode_SumList().

main() reads 5 integers from a user:

   1. The number of nodes to be added to a new list
   2. The value of the first node of the list
   3. An increment between the values of two consecutive nodes.
   4. A value of a new node
   5. The position of a node after which the new node will be added, with 1 indicating the first node

Ex: If the input is:

4 2 5 99 1

the output is:

4 element list: 2 7 12 17 
From second element: 7 12 17 
sum: 38
New list: 2 99 7 12 17 

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode_struct {
   int dataVal;
   struct IntNode_struct* nextNodePtr;
} IntNode;

// Allocate a node for initData
IntNode* IntNode_Create (int initData) {
   IntNode* newNode = (IntNode*)malloc(sizeof(IntNode));
   newNode->dataVal = initData;
   newNode->nextNodePtr = NULL;
   return newNode;
}

/* Insert newNode after node.
 Before: thisNode -- next
 After:  thisNode -- newNode -- next
 */
void IntNode_InsertAfter (IntNode* thisNode, IntNode* newNode) {
   IntNode* tmpNext = NULL;

   tmpNext = thisNode->nextNodePtr;               // Remember next
   thisNode->nextNodePtr = newNode;               // this -- new -- ?
   newNode->nextNodePtr = tmpNext;                // this -- new -- next
}

// Print dataVal
void IntNode_PrintNodeData(IntNode* thisNode) {
   printf("%d ", thisNode->dataVal);
}

// Grab location pointed by nextNodePtr
IntNode* IntNode_GetNext(IntNode* thisNode) {
   return thisNode->nextNodePtr;
}

/* ******** New functions ********/

// Return the length of the list
int IntNode_Length(IntNode* firstNode) {
   int length = 0;
   IntNode* currentNode = firstNode;
   while(currentNode != NULL) {
      ++length;
      currentNode = currentNode->nextNodePtr;
   }

   return length;
}

// Return the Nth element of the list. First node is 1.
IntNode* IntNode_GetNth(IntNode* firstNode, int pos) {
   /* Type your code here. */
   IntNode* currentNode = firstNode;
   for (int i = 1; i < pos; i++)
   {
      currentNode = currentNode->nextNodePtr;
   }
   return currentNode;
}

// Print the entire list starting at firstNode
void IntNode_PrintList(IntNode* firstNode) {
   /* Type your code here. */
   IntNode* currentNode = firstNode;
   while(currentNode != NULL) 
   {
      printf("%d ", currentNode->dataVal);
      currentNode = currentNode->nextNodePtr;
   }
}

// Sum the numbers in the list
int IntNode_SumList(IntNode* firstNode) {
   /* Type your code here. */
   IntNode* currentNode = firstNode;
   int sum = 0;
   while(currentNode != NULL) 
   {
      sum += currentNode->dataVal;
      currentNode = currentNode->nextNodePtr;
   }
   return sum;
}

int main(void) {
   IntNode* firstNode = NULL;
   IntNode* lastNode = NULL;
   IntNode* newNode = NULL;
   IntNode* curNode = NULL;
   int listSize;                                  // how many integers to read
   int increment;                                 // increment between consecutive node values
   int firstNum;                                  // first node value

   // New node for newNum will be inserted after position newPos (first node = 1)
   int newPos;
   int newNum;

   int i;

   // Input:
   scanf("%d %d %d%d %d", &listSize, &firstNum, &increment, &newNum, &newPos);

   // Create the list
   firstNode = IntNode_Create(firstNum);
   // Create node for first value
   // New list has just one node, so lastNode is same as firstNode
   lastNode = firstNode;

   // Add nodes to the list
   for (i = 1; i < listSize; ++i) {
      // Create a new node for the next nmber
      newNode = IntNode_Create((increment * i) + firstNum);
      // Add the node to the end of the list
      IntNode_InsertAfter(lastNode, newNode);
      lastNode = newNode;
   }

   // Print the list
   printf("%d element list: ", IntNode_Length(firstNode));
   IntNode_PrintList(firstNode);
   printf("\n");

   // If list length > 1 print the list starting at the second element
   printf("From second element: ");
   if (IntNode_Length(firstNode) <=1) {
      printf("No second element\n");
   }
   else {
      IntNode_PrintList(IntNode_GetNext(firstNode));
      printf("\n");
   }

   // Print the sum
   printf("sum: %d\n", IntNode_SumList(firstNode));

   // Add a node after node newPos
   newNode = IntNode_Create(newNum);
   curNode = IntNode_GetNth(firstNode, newPos); //ptr of curNode will point to the Nth node, so next line, insert a new node at the *nextNodePtr of the curNode
   IntNode_InsertAfter(curNode, newNode);
   printf("New list: ");
   IntNode_PrintList(firstNode);
   printf("\n");

   return 0;
}
