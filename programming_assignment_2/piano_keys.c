/*
Dou Jingru
CS241L
This program is to display the frequency of the piano, and the next higher
key frequency
*/

#include <stdio.h>
#include <math.h>

int main(void){
	int initialKey = 0;
	scanf("%d", &initialKey);
	double r = pow(2, 1.0/12);
	for(int i =0; i < 5; i++){
		double result = (pow(r,i) * initialKey);
		printf("%0.2f ", result);
	}
	printf("\n");
	return 0;
}
