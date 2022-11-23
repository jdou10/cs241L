
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Dou Jingru 
CS 241
hash_handout.c
 */

int main( int argc, char *argv[] ) {

  if ( argc != 2 ) {
    printf ( "You must enter a single word on the command line\n" );
    return 1;  // Error code for operating system
  }

  char *theData = argv[1];


  // This line is for debugging purposes ONLY
  //printf ( "You entered the word: %s\n", theData );

  unsigned int hashCode = 0;

  // this variable is used to capture the leftmost 4 bits of the hashCode
  unsigned int leftMostFourBits = 0;
 
  /* PUT YOUR CODE BETWEEN THIS COMMENT AND THE CLOSING COMMENT BELOW  */

  // loop over each char in the given input string and
  // update the value of the hash code based on this char
  int i;
  for ( i = 0; i < strlen(theData); i++ ) {
    char nextChar = theData[i];
    hashCode = nextChar + 1;
    leftMostFourBits = hashCode >> 10;
    leftMostFourBits = leftMostFourBits & 3932160;
    if(i != strlen(theData) - 1){
	hashCode = hashCode << 4;
	hashCode = hashCode ^ leftMostFourBits;
    }


    // This line is for debugging purposes ONLY
    //printf ( "The next char is: %c\n", nextChar );

  }

  /* CLOSING COMMENT   */

  printf ( "The hash of %s = %u\n", argv[1], hashCode );

  return 0;   // success code returned to Operating System
}
