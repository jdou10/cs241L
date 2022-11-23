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

int main(int argc, char *argv[]) {
  // Recommendation
  int grid[100][100]; 
  int size;
  scanf("%d", &size);
  //instead three if else here, we can do a for loop after the while loop

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
      exit(0);
    }
    grid[newlineCounter][colCounter] = pixel;
  }//end while

  for(int i =1; i < argc; i++){
    //inside here rotate the function to call

    /*if(strcmp(argv[i], "flip") == 0){*/
    /*i++;*/
    /*char * c = argv[i];*/
    /*if (strcmp(c, "v") == 0){*/
    /*}*/
    /*else if (strcmp(c, "v") == 0)*/

    /*}*/
    /*}*/
    /*else if(strcmp(argv[i], "inv") == 0){*/
    /*[>inv(matrix, );<]*/
    /*}*/

    /*else if(strcmp(argv[i], "redeye") == 0){*/
    /*[>eye(matrix, );<]*/
    /*}*/
    /*else{*/
    /*exit(2);*/
    /*}*/
}

}
/*} */


void inv(int** grid, int row, int col){
  char c = '*';
  char d = ' ';
  for(int i = 0; i <= row; i++){
    for(int j = 0; j <= col; j++){
      if(grid[i][j] == c){
        grid[i][j] = d;
      }else if(grid[i][j] = d){
        grid[i][j] = c;
      }else{
        exit(2);
      }
    }
  }
}


void flip(int** grid, int gridSize, int *gridColSize, int *gridRowSize, 
    int *returnSize, int** returnColSize, int** returnRowSize, int isVertical){

  float col;
  float row;
  char c;
  // Should be parse here.
  /*scanf("%c", &c);*/
  if(isVertical == 1){//converte vertical 

    *returnSize = gridSize;
    *returnRowSize = gridRowSize;
    row = *gridRowSize;
    row /= 2;
    for(int i = 0, tmp; i < gridSize; i++){
      for(int j = 0; j < row; j++){
        /*for(int j = 0; j < row/2; j++){*/
        tmp = grid[i][(*gridRowSize - j - 1)];
        grid[i][*gridRowSize -j -1] = grid[i][j];
        grid[i][j] = tmp;
      }
      return;
      }

    }else if(isVertical == 1){//convert horizontal
                              //**************************************************

      *returnSize = gridSize;
      *returnColSize = gridColSize;
      col = *gridColSize;
      col /= 2;
      for(int i = 0, tmp1; i < gridSize; i++){
        for(int j = 0; j < col; j++){
          /*for(int j = 0; j < col/2; j++){*/
          tmp1 = grid[(*gridColSize - 1 - j)][i];
          grid[*gridColSize - 1 - j][i] = grid[j][i];
          grid[j][i] = tmp1;
        }
        return;
        }
        //*************************************************
        /*
         *returnSize = gridSize;
         int **ret = (int**)malloc(sizeof(int*)*(*returnSize));

         *returnColSize = (int*)malloc(sizeof(int)*(gridSize));

         for(int i = 0; i < *returnSize; i++){
         ret[i]=(int*)malloc(sizeof(int)*(gridColSize[i]));
         returnColSize[0][i] = gridColSize[i];
         }
         for(int i=0; i < gridSize; i++){
         for(int x=0, y=gridColSize[i]-1; x<gridColSize[i]; x++, y--){
         ret[i][x]=grid[i][y];
         }
         }
         return ret;*/
      }else{
        printf("Wrong char\n");
        exit(2);
      }
    }


    bool dfs(int **grid, int i, int j, int row, int col){
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
      char c;

      for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
          if(grid[i][j]=='*' && dfs(grid, i, j, row, col)){
            /*removeChar(grid[i][j], c);*/
            grid[i][j] = ' ';
          }
        }
      }
      return ;
    }
