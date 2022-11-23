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
    char c=0;
    short spaceCounter;
    //char bytes[10000];
    char *bytes = "";
    int i;
    int len;
    
    // read through the input and process any do space into bits
    i=0;
    len=strlen(bytes);
    // while loop to read the input file
    char *b2 = malloc(len + 1000); 
    while(c!=EOF){
        c=getchar();
        spaceCounter=0;
        // find dots then count subsequent spaces
        if(c=='.'){
            c=getchar();
            while(c==' '){
                if(spaceCounter>=3){
		    return 2;
		}//use a different variable other than spacecounter 
                spaceCounter++;
                c=getchar();
             }
        }
	/* spaces number is 0, ignore the dot
	 * spaces number is 1, corresponds to 0 bit
	 * spaces number is 2, corresponds to 1 bit
	 * spaces number is 3 or more, no more characters
	 */
        
        if(spaceCounter!=0){
	    printf("Current position %d\n", i);	
            if(spaceCounter==1){
                //bytes[i]='0';
                b2[len] = '0';
                i++;
            }else if(spaceCounter==2){
                //bytes[i]='1';
                b2[len] = '1';
           	i++;
            }else if(spaceCounter>=3){
                c=EOF;
                if(spaceCounter%8==0){
                    return 0;
                }else{
                    return 1;
                }
            }
        }
    }
    //len=strlen(bytes);
    int currChar;
    currChar=0;
    
    printf("%s", b2);
    
    if(c=='.'){
        //int n=spaceCounter();
        switch(spaceCounter){
            case 1:
	        //means you detected 0 bit
                currChar=currChar<<1;
                break;
	    case 2:
		//means you detected 1 bit
                currChar=currChar<<1;
                currChar++;
                break;
            default:
                printf("Message over\n");
	}
    }

    //currChar=currChar << (1 + spaceCounter);

    // convert each string of 8 bits to decimal then convert to ascii
    //for(j=0; j<=len; j++){
    //    currentBit=(int)b2[j]-48;//testcode
    //    decimalForAscii+=(currentBit*pow(2,k));
    //    k--;
    //    if(k == -1){
    //        printf("%c", (char)decimalForAscii);
    //        k=7;
    //        decimalForAscii=0;
    //    }
    //}
    // if number of bits is not multiple of 8
    
    
    //if(c==' ')
    free(b2);//test code
    printf("\n");
}
