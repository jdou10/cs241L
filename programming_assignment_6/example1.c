/** ****************************  
 * Dou Jingru
 * CS 241
 * programming assignment 6
 * print linked list function 
 *******************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


/* **********************
 *This program modify the portion on the last 
 four functions addFirst, removeLast, clear 
 and set with corresponding requirements
 * *********************/

typedef struct node{   // represents one node in a Linked List
  void *data;   // pointer to data associated with this node
  struct node *next;   // pointer to next node in List
  struct node *prev;   // pointer to previous node in List
} Node;

typedef struct{   // represents a Linked List
  Node *header;   // pointer to the "dummy header node" of the linked list
  int size;      // number of nodes in the Linked List
} LinkedList;


// function proto-types
void createList (LinkedList *someList);
void addEnd (LinkedList *someList, void *newElement);
void *delete (LinkedList *someList, int position);
void outputList (LinkedList *someList);
void addFirst (LinkedList *someList, void *newElement);
void *removeLast (LinkedList *someList);
void clear (LinkedList *someList);
void *set (LinkedList *someList, int position, void *newElement);

#define MAX_NAME_LENGTH 20

int main() {
  LinkedList myList;    
  LinkedList *roster = &myList;
  createList (roster);  // initialize the fields of the list
                        // process a sequence of List operations from stdin

  int curr_pos;
  char curr_strings[10000][20];
  int curr_string = 0;

  char action = getchar();
  while(action != EOF){
    switch(action){
      case 'a':
        scanf("%s", curr_strings[curr_string]);
        addEnd(roster, curr_strings[curr_string]);
        curr_string++;
        break;
      case 'd':
        scanf("%d", &curr_pos);
        delete(roster, curr_pos);
        break;
      case 'o':
        outputList(roster);
        break;
      default:
        // TODO
        break;
    }
    while(action != '\n')
      action = getchar();
    action = getchar();
  }
} 


// Initially the List is empty
// We must create memory for the "dummy header node"
void createList (LinkedList *someList){
  someList->size = 0; 
  someList->header = malloc(sizeof(Node));
  someList->header->data = NULL;
  someList->header->next = someList->header;
  someList->header->prev = someList->header;
}

// add the new data element to the end of the List
void addEnd(LinkedList *someList, void *newData){
  Node *lastNode = someList->header->prev;
  Node *newNode = malloc(sizeof(Node));
  newNode->data = newData;          // set the fields of the new Node
  newNode->next = someList->header;
  newNode->prev = someList->header->prev;
  someList->header->prev->next = newNode;  // splice-in the newNode
  someList->header->prev = newNode;        // into the List
  someList->size++;
}



// remove the item in the given positionn in the List, and
// return that data
void *delete (LinkedList *someList, int position){
  if (position < 0 || position >= someList->size) 
    exit(2);
  // walk down the list until we reach the node to be removed
  Node *temp = someList->header;
  for (int i=0; i <= position; i++)
    temp = temp->next;
  void *removedData = temp->data;
  temp->prev->next = temp->next;   // splice-out the Node
  temp->next->prev = temp->prev; 
  someList->size--;
  free(temp);   // free-up the memory of the deleted Node
  return (removedData);
}


// output the contents of the List
// it is assumed that the elements in the list are strings
void outputList(LinkedList *someList){
  if(someList == NULL)
    return;
  if(someList->size == 0){
    printf("[]\n");
    return;
  }
  printf ("[");
  Node *temp = someList->header->next;
  for(int num = 0; num < someList->size; num++){
    printf("%s%s", (char *) temp->data,
        (num < someList->size-1) ? " " : "" );
    temp = temp->next;
  }
  printf ( "]\n" );
}


// add the newElement to position 0 in the List
// that is, the newElement precedes all other elements in the list
void addFirst(LinkedList *someList, void *newElement){ 
  //************************************ 
  //Node *node=(Node*)malloc(sizeof(Node));
  //node->data=data;
  //if(someList->header == NULL){
  //    node->next=NULL;
  //}else{
  //    node->next=list->head;
  //}
  //list->head=node;

  //*************************************
  //Node *newNode = malloc(sizeof(Node));
  //newNode->data = newElement;
  //newNode->next = someList;
  //someList->next = newNode;
  //someList->size++;

  //*************************************
  Node *temp, *header;
  header=someList->header;
  temp = malloc(sizeof(Node));
  temp->data = newElement;
  temp->next = header->next;
  header->next = temp; 
}


// remove the last element in the list, and return a pointer
// to that data item.
// if the list is empty, exit the program with status 2
void *removeLast(LinkedList *someList) {
  //***************************
  //Node *position, *temp;
  //position=someList->next;
  //while(position->data != temp){
  //    prev=position;
  //position = position->next;
  //}
  //prev->next = position->next;
  //free(position);
  return NULL;
}


// this function effectively empties the list
void  clear(LinkedList *someList){
  //**********************
  //data = header;
  //header = header->next;
  //free(data);

  //**********************
  Node *curr, *temp;
  curr = someList->header->next;
  int curr_size = someList->size;
  while(curr_size--){
    temp = curr->next;
    free(curr);
    curr=temp;
  }
}


// alter the data in the given position in the List to
// be the newElement.  Return a pointer to the data that
// was over-written and deleted from the list
// if the position is illegal then exit the program with status 2
void *set(LinkedList *someList, int position, void *newElement){
  //**************************************************
  //position has to be 1
  if(position<1){
    return 0;
  }
  //find a node in the position
  //front and position can not be teh same, it 
  //will always point at the next node as j pointed at
  Node *front = someList->header;
  for(int j=1; j<position; j++){
    front=front->next;
    if(front==NULL){
      return 0;
    }
  }
  //create a new empty node to store the newElement
  Node *temp = malloc(sizeof(Node));
  temp->data = newElement;
  //insert the node
  temp->next = front->next;
  front->next = temp;
  return NULL;

  //******************************************
  //position = someList->next;
  //while(position){
  //    if(position->data==temp){
  //        position->data=newElement;
  //    }
  //    position=position->next;
  //}

  //over-write
  //prev = someList;
  //position=0;
  //for(position=1; position < size; position++){
  //    prev
  //position = (Node *)malloc(sizeof(Node));
  //position->data=temp;
  //position->next=prev->next;
  //prev->next=position;
  //return NULL;
}

