/* Dou Jingru
 cs 241L
 This program is modified from myshapes.out to newshapes.c, by changing the 
 character decimal value minus nine in ascii table
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*function to replace ascii symbol to another*/ 

int main(void){
    const int SHIFT = -9;
    char a,b,d,e,f,g,h;
    printf("______________        ****             +\n");
    printf(":            :     ****  ****         / \\\n");
    printf(":            :    ****    ****       /   \\\n");
    printf(":            :   ****      ****     /     \\\n");
    printf(":            :   ****      ****    /       \\\n");
    printf(":            :    ****    ****    /         \\\n");
    printf(":            :     ****  ****    /           \\\n");
    printf("______________        ****      /_____________\\\n");
    return 0;
}
