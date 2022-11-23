/* *********************************
Jingru Dou
proj#4
DNA.c, the file is to count the
percentage of letters A,C,G,T
in a DNA sequen
********************************* */

#include <stdio.h>
#include <stdlib.h>

/* *********************************
Function's algorithm is used switch case
included in a while loop, count all the
letters start from 0 at the beginning,
if it is not the letters from the file-EOF
then exit the program
Parameters and type() are char and int
Function's return value is 0
********************************* */

int main(int argc, char *argv[]){
    float aCount, cCount, gCount, tCount;
    aCount=0;
    cCount=0;
    gCount=0;
    tCount=0;
    char inputc;
    inputc = getchar();
    while(inputc!=EOF){
	switch(inputc){
	    case 'A':
            case 'a':
	        aCount++;
                break;
	    case 'C':
            case 'c':
		cCount++;
                break;
	    case 'G':
            case 'g':
		gCount++;
                break;
	    case 'T':
            case 't':
		tCount++;
                break;
	    case ' ':
		break;
            case '\t':
                break;
	    case '\n':
		break;
	    default:
	        return 1;
	}
        inputc = getchar();
    }

    int sequenceLength;
    float aPercent, cPercent, gPercent, tPercent;
    sequenceLength=(int)aCount+(int)cCount+(int)gCount+(int)tCount;

    aPercent=((float)aCount/(float)sequenceLength)*100;
    cPercent=((float)cCount/(float)sequenceLength)*100;
    gPercent=((float)gCount/(float)sequenceLength)*100;
    tPercent=((float)tCount/(float)sequenceLength)*100;

    printf("The DNA sequence has %d bases \n", sequenceLength);
    printf("\b%6.2f%% of the bases are A\n", aPercent);
    printf("\b%6.2f%% of the bases are C\n", cPercent);
    printf("\b%6.2f%% of the bases are G\n", gPercent);
    printf("\b%6.2f%% of the bases are T\n", tPercent);
    return 0;
}
