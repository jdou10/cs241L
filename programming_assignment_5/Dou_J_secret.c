/* ************************************
 * Dou Jingru
 * CS241
 * Programming Assignment 5
 * read the seceret message of the text
 *********************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ***************************************
 * This program is dedicated to 
 * first scan the text for dot space
 * comma aka divided to 0's or 1's
 * and then count the spaces as ascii 0x20
 * second part to print out the secret
 * message using a for loop
 ************************************** */

int main(int argc, char *argv[]){
    char c;
    char bytes[100000];
    short spaceCounter;
    int currChar;
    int num_bits_detected;
    int curr_pos;
    
    //initialize to 0
    c=0;
    num_bits_detected=0;
    currChar=0;
    curr_pos=0;
   
    //read through the input and process any space into bits
    //while loop to read the input file 
    while(c!=EOF){
        c=getchar();
        spaceCounter=0;
        //find dots then count subsequent spaces
        if(c=='.'){
            c=getchar();
            while(c==' '){
                spaceCounter++;
                c=getchar();
            }
           
            switch(spaceCounter){
                case 1:
                    //detected 0 bit, number spaces is 1
                    currChar=currChar<<1;
                    break;
                case 2:
                    //detected 1 bit, number spaces is 2
                    currChar=currChar<<1;
                    currChar++;
                    break;
                default:
		    //if program successfully run return 0
                    if(num_bits_detected%8==0){
                        printf("%s", bytes);
                        return 0;
                    }
		    //if program not multiple of 8 return 1
		    else{
                        return 1;
                    }
            } // end switch

            num_bits_detected++;
	   
	    //if is multiple of 8, count the position
            if(num_bits_detected==8){
                bytes[curr_pos]=currChar;
                currChar=0;
                curr_pos++;
                num_bits_detected=0;
            }
        }
    }
    //if program not contain the signal return 2
    return 2;
}
