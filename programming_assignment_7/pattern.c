// CS 271 - PA 2
// Program name: pattern.c
// Jingru Dou
// 11 February 2021


#include <stdio.h>
#include <stdlib.h>

int main(){
    int line;  // Total lines in rhombus pattern
    int column;  // Total columns in rhombus pattern
    int i;  // Current lines
    int j;  // Current columns
    
    printf("Please enter the line number：");
    scanf("%d", &line);
    
    if(line <= 2) { 
        printf("Line numbers must be greater than 2.\n");
    } // end if
    
    
    column = line;  // Total lines is equal to total columns
    
    for(i = 1; i <= line; i++) {  // Go through every lines
        if(i < (line + 1) / 2 + 1) {  // The half top part(include the middle line)
            for(j = 1; j <= column; j++) {  // Go through all the columns on the top part
                if( (column + 1) / 2 - (i - 1) == j || j == (column + 1) / 2 + (i - 1) ) {
                    printf("*");
                } else {
                    printf(" ");
                } // end else
                 
            } // end for loop
        
    
        } else {  // The bottom half part
            for(j = 1; j <= column; j++) {  // Go through all the columns in the bottom part
                if( (column + 1) / 2 - (line - i) == j || j == (column + 1) / 2 + (line - i) ) {
                    printf("*");
                } else {
                    printf(" ");
                } // end else
            } // end for loop
            
        } // end else
        printf("\n");
        
    } // end for loop
    return 0;

} // end main
