/** ****************************  
 * Dou Jingru
 * CS 241
 * programming assignment 7
 * printing image 2-D array 
 *******************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ***********************************
This program has several function and 
dedicated to invert, remove red eye and
flip an image. In the main function is
for printing and checking, and each 
function just do its own job. dfs function
is putting the image in index for red eye
function.
 * **********************************/

#define MAX_SIZE 100

void printImage(int size, char grid[MAX_SIZE][MAX_SIZE]);
void inv(int size, char grid[MAX_SIZE][MAX_SIZE]);
void flip(int size, char grid[MAX_SIZE][MAX_SIZE], char c);
void redeye(int size, char grid[MAX_SIZE][MAX_SIZE]);


int main(int argc, char *argv[]) {
    int size;
    int check = scanf("%d", &size);
    if(check != 0 && check < 1){ 
        exit(1);// if char(i.e abc)
    }
    if(size < 1){
        exit(1);// size at least 1*1
    }
    char grid[MAX_SIZE][MAX_SIZE];
    char pixel;
    int i, j;
    pixel = getchar();
    pixel = getchar();
    
    for(i=0; i < size; i++){
        for(j=0; j < size; j++){
            grid[i][j] = pixel;
            pixel = getchar();
        }
        pixel = getchar();
    }
    if((i != size) || (j != size)){
        exit(1);// if rows and columns not equal
    }
    
    // parse parameters
    // inside here rotate the function to call
    for(int i = 1; i < argc; i++){
        if(argc == 1){
            printImage(size, grid);
        }
        if(strcmp(argv[i], "flip") == 0){
            i++;
            if(i >= argc){
                exit(2);// if nothing after flip
            }
            if((strcmp(argv[i], "v") != 0) && (strcmp(argv[i], "V") != 0)
             &&(strcmp(argv[i], "h") != 0) && (strcmp(argv[i], "H") != 0)){
                exit(2);// if not v,V,h,H
            }
            flip(size, grid, argv[i][0]);
        }else if(strcmp(argv[i], "inv") == 0){
            inv(size, grid);
        }else if(strcmp(argv[i], "redeye") == 0){
            redeye(size, grid);
        }else{
            exit(2);// if not desired transformation calls
        }
    }
    printImage(size, grid);
    exit(0);// program succeed
} 


void printImage(int size, char grid[MAX_SIZE][MAX_SIZE]){
    int i, j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(grid[i][j] != '*' && grid[i][j] != ' '){
                exit(1);// if char is not '*' or ' '
            }else{
                printf("%c", grid[i][j]);
            }
        }
        printf("\n");
    }
}


void inv(int size, char grid[MAX_SIZE][MAX_SIZE]){
    char c = '*';
    char d = ' ';
    int i, j; 
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(grid[i][j] == c){
                grid[i][j] = d;
            }else if(grid[i][j] == d){
                grid[i][j] = c;
            }else{
                exit(1);// if char is not '*' or ' '
            }
        }
    }
}


void flip(int size, char grid[MAX_SIZE][MAX_SIZE], char c){
    int i, j;
    char temp;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(grid[i][j] != '*' && grid[i][j] != ' '){
                exit(1);// if char is not '*' or ' '
            }
        }
    }
    if(c == 'h' || c == 'H'){
        for(i = 0; i < size/2; i++){
            for(j = 0; j < size; j++){
                temp = grid[i][j];
                grid[i][j] = grid[size - 1 - i][j];
                grid[size - 1 - i][j] = temp;
            }   
        }
    }
    if(c == 'v' || c == 'V'){
        for(i = 0; i < size; i++){
            for(j = 0; j < size/2; j++){
                temp = grid[i][j];
                grid[i][j] = grid[i][size - 1 - j];
                grid[i][size - 1 - j] = temp;
            }
        }
    }
}


void redeye(int size, char grid[MAX_SIZE][MAX_SIZE]){
    int i, j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(grid[i][j] != '*' && grid[i][j] != ' '){
                exit(1);// if char is not '*' or ' '
            }
        }
    }
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){	    
            if((i-1 >= 0) && (grid[i-1][j] != ' ')){
                continue;
            }
            if(i+1 < size && (grid[i+1][j] != ' ')){
                continue;
            }
            if(j-1 >= 0 && (grid[i][j-1] != ' ')){
                continue;
            }
            if(j+1 < size && (grid[i][j+1] != ' ')){
                continue;
            }
            if((i-1 >= 0) && (j-1 >= 0) && (grid[i-1][j-1] != ' ')){
                continue;
            }
            if((i-1 >= 0) && (j+1 < size) && (grid[i-1][j+1] != ' ')){
                continue;
            }
            if((i+1 < size) && (j-1 >= 0) && (grid[i+1][j-1] != ' ')){
                continue;
            }
            if((i+1 < size) && (j+1 < size) && (grid[i+1][j+1] != ' ')){
                continue;
            }
            grid[i][j] = ' ';
        }
    } 
}
