/* ***************
Jingru Dou
CS241
HW#2 question6.30
*************** */

#include <stdio.h>

/* *****************************
This program is to count all the
prime numbers between 1 to 1000
***************************** */
int main() {
    int n=1000;
    int prime[n];
    for(int i=0; i<n; i++) {
        prime[i] = 1; // initialize to 1
    } 
    prime[0]=0;
    primt[1]=0;
    for(int i=1; i<n; i++) {
        if(prime[i]==1){
            //starting from subscript 2
            for(int j=2; j<i; j++) {
            //multiples of 2 are set to 0, and so on
                if(i%j==0) {
                    prime[i]=0;
                    break;
                }
            }
        }
    }
    //print all the prime number
    for(int i=1; i<n; i++) {
        if(prime[i]==1){
            printf("%d\t", i);
        }
    }
    printf("\n");
    return 0;
}