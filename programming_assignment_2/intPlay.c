/* 
 * Author: Dr. Soraya Abad-Mota
 * Playing with integers and their representation
 */
#include <stdio.h> /* This is an include directive */

int main(void){
  short si, sj;
  int x, y;
  x = 70000;
  printf("x in hex is:  %x\n", x);
  // 1. Does the value you see in x has an indication of it being a negative 
  // number? Why?
  si = x;
  printf("si got x and its value in hex is: %x\n", si);
  // 2. Why is the value of si different from the value of x? 
  // in the program x was assigned to si
  // Explain clearly and concisely.
  sj = si * si;
  printf("si squared is? %x\n", sj);
  // 3. How do you explain the result of si^2 being < si?
  y =  si * si;
  printf("y contains also si squared, it's value is: %x\n",y);
  // 4. What is your conclusion?
  return 0;
}

