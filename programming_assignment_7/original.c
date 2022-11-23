/** ****************************  
 * Dou Jingru
 * CS 241
 * programming assignment 7
 * printing image 2-D array 
 *******************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ***********************************
This program has several function and 
dedicated to invert, remove red eye and
flip an image. In the main function is
for printing and checking, and each 
function just do its own job. dfs function
is putting the image in index for red eye
function.
 * **********************************/

//#define ROW 100
//#define COL 100

void printImage(char grid[size][size], int size);
void inv(char grid[size][size], int size);
void flip(char grid[size][size], char c, int size);
bool dfs(char grid[size][size], int size);
void redeye(char grid[size][size], int gridSize, int *gridColSize);


int main(int argc, char *argv[]) {
    char grid[ROW][COL];
    int size;
    
    //scanf("%d\n", &size);
    //if(!isdigit(size)){
	//printf("pixel exit\n");
	//exit(1);
    //}
    int check = scanf("%d\n\n", &size);
    if(check != 0 && size < 1){ 
        exit(1);
    }
    printf("pixel-1\n");
    //scanf("%d\n\n", check);


    char pixel;
    int newlineCounter;//also means rowCounter
    int colCounter;
    while((pixel=getchar()) != EOF){     
	if(grid[ROW][COL] != ' ' && grid[ROW][COL] != '*'){
	    printf("pixel-2\n");
	    exit(1);
        }	    
	printf("pixel-3\n");
	if(colCounter != newlineCounter){
	    printf("pixel1.2\n");
            exit(1);
	}
	//newlineCounter = pixel++;
	//colCounter = pixel++;
	if(pixel != '\n') exit(1);
        if(pixel == '\n'){
            newlineCounter++;            
            if(colCounter != size){
                printf("pixel3 %i \n", colCounter);
                
            }
            pixel=getchar();
            printf("pixel-4\n");
            colCounter = 0;
            //newlineCounter++;
        }else{	    
            grid[newlineCounter][colCounter] = pixel;
            pixel = getchar();
	}
        pixel = getchar();
        if(newlineCounter == size && colCounter != 0){
            printf("pixel-5\n");
            exit(1);
        }
        printf("pixel-6\n");
        colCounter++;
        //matrix[newlineCounter][colCounter] = pixel;
    }//end while

    ++newlineCounter;
    printf("%d newline counter\n", newlineCounter);
    printf("%d size\n", size);
    if(newlineCounter != size){
        printf("pixel-7\n");
        exit(1);    
    }
    if(newlineCounter == size && colCounter == size){
        printf("pixel-8\n");
        exit(0);
    }      
    //printf("&grid[%d][%d] = %c\t", i, j, &grid[i][j]);
    
     
    // parse parameters
    for(int i = 1; i < argc; i++){
	//inside here rotate the function to call
        if(strcmp(argv[i], "flip") == 0){
            i++;
            if((strcmp(argv[i], "v") != 0) && (strcmp(argv[i], "V") != 0)
             &&(strcmp(argv[i], "h") != 0) && (strcmp(argv[i], "H") != 0)){
                exit(2);
            }
            if(strcmp(argv[i], "v") == 0){
                flip(grid, argv[i], size);
                printImage(grid, size);	
            }else if(strcmp(argv[i], "V") == 0){
                flip(grid, argv[i], size);
                printImage(grid, size);
            }else if(strcmp(argv[i], "h") == 0){
                flip(grid, argv[i], size);
                printImage(grid, size);
            }else if(strcmp(argv[i], "H") == 0){
                flip(grid, argv[i],size);
                printImage(grid, size);
            }else{
                exit(2);
            }
        }else if(strcmp(argv[i], "inv") == 0){
            inv(grid, size);
            printImage(grid, size);
        }else if(strcmp(argv[i], "redeye") == 0){
            //redeye(grid, size, pixel);
            printImage(grid, size);
        }else if(strcmp(argv[i], " ") == 0){
            printImage(grid, size);
        }else{
            printf("exit to else\n");
            exit(2);
        }
    }
} 

void printImage(char grid[][COL], int size){
    int i, j;
    printf("image\n");
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
	    printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void inv(char grid[][COL], int size){
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
                exit(2);
            }
        }
    }    
}


void flip(char grid[][COL], char c, int size){
    int i, j;
    char temp;
    //char c_1[O] = "v", c_2[O] = "V";
    //char c_3[O] = "h", c_4[O] = "H";

    //scanf("%d %d\n", &row, &col);
    
    if(c == 'v' || c == 'V'){//vertical
        for(i = 0; i < size/2; i++){
            for(j = 0; j < size; j++){
		temp = grid[i][j];
		grid[i][j] = grid[size-1-i][j];
                grid[size-1-i][j] = temp;
            }   
        }
    }/*
    if(c == 'h' || c == 'H'){//vertical
        for(i = 0; i < row/2; i++){
            for(j = 0; j < col; j++){
                temp = grid[i][j];
                grid[i][j] = grid[row-1-i][j];
                grid[row-1-i][j] = temp;
            }
        }
    }*/
    if(c == 'h' || c == 'H'){//horizontal
        for(i = 0; i < size; i++){
            for(j = 0; j < size/2; j++){
		temp = grid[i][j];
		grid[i][j] = grid[i][size-1-j];
		grid[i][size-1-j] = temp;
            }
        }
    }/*
    if(strcmp(c, c_4) == 0){//horizontal
        for(i = 0; i < row; i++){
            for(j = 0; j < col/2; j++){
                temp = grid[i][j];
                grid[i][j] = grid[i][col-1-j];
                grid[i][col-1-j] = temp;
            }
        }
    }*/
}

/*
bool dfs(char grid[][COL], int row, int col){
    int i, j;
    if(i < 0 || i >= row || j < 0 || j >= col){
        return false;
    }
    if(grid[i][j] == 1){
        return true;
    }
    grid[i][j] = 1;
    bool up = dfs(grid, i-1, j, row, col);
    bool down = dfs(grid, i+1, j, row, col);
    bool left = dfs(grid, i, j-1, row, col);
    bool right = dfs(grid, i, j+1, row, col);
    bool upleft = dfs(grid, i-1, j-1, row, col);
    bool upright = dfs(grid, i-1, j+1, row, col);
    bool downleft = dfs(grid, i+1, j-1, row, col);
    bool downright = dfs(grid, i+1, j+1, row, col);

  
    return up && down && left && right && upleft && 
	    upright && downleft && downright;
}

void redeye(char grid[][COL], int gridSize, int *gridColSize){
    int row = gridSize;
    int col = gridColSize[0];
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j]=='*' && dfs(grid, i, j, row, col)){
                grid[i][j] = ' ';
            }
        }
    }
    return grid[i][j];
}
*/
