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

/* ***********************************
This program has several function and 
dedicated to invert, remove red eye and
flip an image. In the main function is
for printing and checking, and each 
function just do its own job. dfs function
is putting the image in index for red eye
function.
 * **********************************/

//#define MAX_SIZE 100
void inv(int** grid, int row, int col);
void flip(int row, int col, int choice);
void redeye(int** grid, int gridSize, int *gridColSize);

int main(int argc, char *argv[]) {
    char matrix[100][100]; 
    int size;
    
    scanf("%d", &size);

    char pixel;
    int newlineCounter;//also means rowCounter
    int colCounter;
    while((pixel=getchar()) != EOF){     
        if(pixel == '\n'){
            if(newlineCounter != size){
                exit(1);
            }
            if(newlineCounter != colCounter){
                exit(1);
            }
            colCounter = 0;
            newlineCounter++;
        }
        if(newlineCounter == size && colCounter != 0){
            exit(1);
        }
        if(newlineCounter == size && colCounter == size){
            printf("%c", matrix[newlineCounter][colCounter]);
	    return 0;
        }
        matrix[newlineCounter][colCounter] = pixel;
    }//end while
    
    // have no idea where does this come from
    //printf("&grid[%d][%d] = %c\t", i, j, &grid[i][j]);

    for(int i = 1; i < argc; i++){
        char * c = argv[i];
	//inside here rotate the function to call
        if(strcmp(argv[i], "flip") == 0){
            i++;
	    if(strcmp(c, "v") == 0){
                flip(newlineCounter, colCounter, 1);
	        printf("%c", matrix[newlineCounter][colCounter]);	
	    }else if(strcmp(c, "V") == 0){
                flip(newlineCounter, colCounter, 1);
	    }else if(strcmp(c, "h") == 0){
	        flip(newlineCounter, colCounter, 0);
	    }else if(strcmp(c, "H") == 0){
	        flip(newlineCounter, colCounter, 0);
	    }else{
	        exit(2);
	    }
        }else if(strcmp(argv[i], "inv") == 0){
            //for( ){
	        //inv(grid, &c);
	    //}
        }else if(strcmp(argv[i], "redeye") == 0){
            //for(int i = 1; i <  ; i++){
                //redeye(grid, &c);
	    //}
        }else{
            exit(2);
	}
    }
} 


void inv(int** grid, int row, int col){
    char c = '*';
    char d = ' '; 
    for(int i = 0; i <= row; i++){
        for(int j = 0; j <= col; j++){
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


void flip(int row, int col, int choice){
    char grid[100][100];
    
    scanf("%d %d\n", &row, &col);
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
	    scanf("%c", &grid[i][j]);
	}
	scanf("\n");
    }
    scanf("%d\n", &choice);

    if(choice == 1){ 
        for(int i = 0; i < row/2; i++){
            for(int j = 0; j < col; j++){
		int tmp = grid[i][j];
		grid[i][j] = grid[row-1-i][j];
                grid[row-1-i][j] = tmp;
            }
	    printf("\n");
        }
    }
    //scanf("%d\n", &isHorizontal);
    if(choice == 0){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col/2; j++){
		int tmp = grid[i][j];
		grid[i][j] = grid[i][col-1-j];
		grid[i][col-1-j] = tmp;
            }
	    printf("\n");
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
	    printf("%c", grid[i][j]);
        }
	printf("\n");
    }
}


bool dfs(int** grid, int i, int j, int row, int col){
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

void redeye(int** grid, int gridSize, int *gridColSize){
    int row = gridSize;
    int col = gridColSize[0];
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j]=='*' && dfs(grid, i, j, row, col)){
                grid[i][j] = ' ';
            }
        }
    }
    return ;
}
