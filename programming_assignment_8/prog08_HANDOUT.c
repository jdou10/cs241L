#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define VALIDNODE(N, M) (0 <= N && N < M)
#define INSERT_CHILD(BRANCH)\
  if(BRANCH != NULL)\
  return false;\
  else {\
    BRANCH = initNode(childData);\
    return true;\
  }

typedef struct node {   // represents one node in a Binary Tree

  int           data;   // data associated with this node
  struct node  *left;   // pointer to left-child node in tree
  struct node  *right;  // pointer to right-child node in tree

} Node;

typedef struct { 

  Node  *root;   // pointer to the root node of the tree

} BinaryTree;

// function proto-types
Node *initNode(int);
void  toString ( Node *someTree );
void  preorder( Node *curr );
void  postorder( Node *curr );
int   size( Node *curr );
int   height( Node *curr );
bool  contains( Node *curr, int target );
bool  isHeapOrdered ( Node *curr );
int   numSingleChild ( Node *curr );
void  makeMirror ( Node *curr );

void freeNode(Node *);
bool insertChildNode(Node *, int, char, int);

void createBinaryTree(BinaryTree **);
void freeBinaryTree(BinaryTree *);
void processStdIn(BinaryTree *);
bool insertChildBinaryTree(BinaryTree *, int, char, int);

void cleanExit(BinaryTree *, int);

int main(int argc, char * argv[]) {

  BinaryTree * myTree;
  createBinaryTree(&myTree);
  processStdIn(myTree);

  // TODO
  // process a sequence of BinaryTree operations from command line arguments

  // Free memory from nodes
  freeBinaryTree(myTree);
}

// create an initialize a tree Node with the given data
Node *initNode ( int theData ){
  Node *theNode;

  theNode = malloc ( sizeof( Node ) );
  theNode->data = theData;
  theNode->left = NULL;
  theNode->right = NULL;

  return( theNode );
}

// output the contents of the Tree 
void toString( Node *root )
{
  preorder ( root );  // kick-start the recursion

  printf ( "\n" );
}

// output the contents of the Tree in PREORDER
void preorder( Node *curr )
{
  if ( curr == NULL ) {

    return;          // tree is empty, nothing to output
  }
  else {

    printf ( "%d ", curr->data );

    preorder ( curr->left );  // left subtree

    preorder ( curr->right );  // right subtree
  }
}

// output the contents of the Tree in POSTORDER
void postorder( Node *curr )
{
  if ( curr == NULL ) {

    return;          // tree is empty, nothing to output
  }
  else {

    postorder ( curr->left );  // left subtree

    postorder ( curr->right );  // right subtree

    printf ( "%d ", curr->data );
  }
}

// TODO
// return true if-and-only-if the subtree pointed to by
// the paramter curr is "heap-ordered", that is, the value in
// each node is smaller than its parent value
bool isHeapOrdered( Node *curr )
{
  return true;   // dummy place-holder code
}


// TODO
// return the number of nodes in the tree that have exactly
// one child
int numSingleChild ( Node *curr )
{
  return -99;   // dummy place-holder code
}


// TODO
// transform the subtree pointed to by curr to be its mirror-image,
// that is, the right child becomes the left child, and vice versa
void makeMirror ( Node *curr )
{
}

// return the number of nodes in the subtree
int size( Node *curr )
{
  if ( curr == NULL ) {

    return 0;          // tree is empty
  }
  else {

    int leftSize = size ( curr->left );    // left subtree

    int rightSize = size ( curr->right );  // right subtree

    return ( leftSize + rightSize + 1 );
  }
}


// return the height of the subtree pointed to by curr
int height( Node *curr )
{
  if ( curr == NULL ) {

    return -1;          // tree is empty
  }
  else {

    int leftHeight = height ( curr->left );    // left subtree

    int rightHeight = height ( curr->right );  // right subtree

    if ( leftHeight > rightHeight )

      return leftHeight + 1;

    else

      return rightHeight + 1;
  }
}


// return true if-and-only-if the subtree below curr
// contains the given target
bool contains( Node *curr, int target )
{
  if ( curr == NULL ) 

    return false;          // tree is empty

  else if ( curr->data == target )

    return true;

  else {

    bool leftSide = contains ( curr->left, target );   // left subtree

    if ( leftSide )
      return true;

    bool rightSide = contains ( curr->right, target ); // right subtree

    return ( rightSide );
  }
}

void freeNode(Node * n){
  if(n != NULL){
    if(n->left != NULL)
      freeNode(n->left);
    if(n->right != NULL)
      freeNode(n->right);
    free(n);
  }
}

bool insertChildNode(Node * n, 
    int parentData, char branch, int childData){
  if(n == NULL) return false;

  if(n->data == parentData){
    switch(branch){
      case 'l':
        INSERT_CHILD(n->left);
      case 'r':
        INSERT_CHILD(n->right);
      default:
        return false;
    }
  }

  return 
    insertChildNode(n->left, parentData, branch, childData) || 
    insertChildNode(n->right, parentData, branch, childData);
}

void createBinaryTree(BinaryTree ** bt){
  *bt = (BinaryTree *)malloc(sizeof(BinaryTree));
  (*bt)->root = NULL;
}

void freeBinaryTree(BinaryTree * bt){
  if(bt != NULL){
    freeNode(bt->root);
    free(bt);
  }
}

void processStdIn(BinaryTree * bt){

  if(bt == NULL) return;

  int numNodes, checkNumNodes;
  int numChildInsertions, checkChildInsertions;
  int rootNum, checkRootNum;
  int currParentNode, currChildNode;
  char currBranch;

  checkNumNodes = scanf("%d\n", &numNodes);

  if(checkNumNodes != 1 || numNodes < 0) cleanExit(bt, 1);

  checkChildInsertions = scanf("%d\n", &numChildInsertions);
  if(checkChildInsertions != 1) cleanExit(bt, 1);

  checkRootNum = scanf("%d\n", &rootNum);
  if(checkRootNum != 1) cleanExit(bt, 1);

  // initialize root node
  bt->root = initNode(rootNum);

  // process Node data from stdin
  while(numChildInsertions-- > 0){
    int checkLine = scanf("%d %c %d\n", 
        &currParentNode, &currBranch, &currChildNode);

    if(checkLine != 3)                       cleanExit(bt, 1);
    if(!VALIDNODE(currParentNode, numNodes)) cleanExit(bt, 1);
    if(!VALIDNODE(currChildNode,  numNodes)) cleanExit(bt, 1);

    if(currBranch == 'l' || currBranch == 'r')
      insertChildBinaryTree(bt, currParentNode, currBranch, currChildNode);
    else
      cleanExit(bt, 1);
  }
}

bool insertChildBinaryTree(BinaryTree * bt, 
    int parentData, char branch, int childData){
  return insertChildNode(bt->root, parentData, branch, childData);
}

void cleanExit(BinaryTree * bt, int exitCode){
  freeBinaryTree(bt);
  exit(exitCode);
}
