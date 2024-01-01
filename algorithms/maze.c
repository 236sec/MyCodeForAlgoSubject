#include <stdio.h>
#include <stdlib.h>

int isCanMove(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int traverseMaze(char** maze,int x,int y,int n,int dr){
  //dr=1 go down traverseMaze(a,row_s+1,col_s,n,1)
  //dr=2 go up traverseMaze(a,row_s-1,col_s,n,2)
  //dr=3 go right traverseMaze(a,row_s,col_s+1,n,3)
  //dr=4 go left traverseMaze(a,row_s,col_s-1,n,4)
    if(isCanMove(x,y,n)==0){
      return 0;
    }
    if(maze[x][y] == 'G'){
      return 1;
    }else if(maze[x][y] == '#'){
      return 0;
    }else if(maze[x][y] == ' '){
      
      if(dr==1){
        //dont go up
        if(traverseMaze(maze,x+1,y,n,1)||traverseMaze(maze,x,y+1,n,3)||traverseMaze(maze,x,y-1,n,4)){
          maze[x][y] = '.';
        }
      }
      if(dr==2){
        //dont go down
        if(traverseMaze(maze,x-1,y,n,2)||traverseMaze(maze,x,y+1,n,3)||traverseMaze(maze,x,y-1,n,4)){
          maze[x][y] = '.';
        }
      }
      if(dr==3){
        //dont go left
        if(traverseMaze(maze,x+1,y,n,1)||traverseMaze(maze,x-1,y,n,2)||traverseMaze(maze,x,y+1,n,3)){
          maze[x][y] = '.';
        }
      }
      if(dr==4){
        //dont go right
        if(traverseMaze(maze,x+1,y,n,1)||traverseMaze(maze,x-1,y,n,2)||traverseMaze(maze,x,y-1,n,4)){
          maze[x][y] = '.';
        }
      }
    }else if(maze[x][y] == 'S'){
      return 0;
    }
}

int maintttasd(void){
  int n;
  scanf("%d\n",&n);
  //create array to store str
  int row_s,col_s;
  char** a = NULL;
  a = (char**)malloc(sizeof(char*)*n);
  for(int i = 0 ; i < n ; i++){
    
    char user_str[50];
    fgets(user_str, sizeof(user_str), stdin);
    user_str[strcspn(user_str, "\n")] = '\0';
    
    int len = strlen(user_str);
    a[i] = (char*)malloc(sizeof(char)*(len+1));
    strcpy(a[i], user_str);
    
    char *result = strchr(user_str, 'S');
    if(result!=NULL){
      int index = result - user_str;
      row_s = i;
      col_s = index;
    }
  }
  
  traverseMaze(a,row_s+1,col_s,n,1);
  traverseMaze(a,row_s-1,col_s,n,2);
  traverseMaze(a,row_s,col_s+1,n,3);
  traverseMaze(a,row_s,col_s-1,n,4);
  for (int i = 0; i < n; i++) {
    printf("%s\n", a[i]);
  }
  
  for (int i = 0; i < n; i++) {
    free(a[i]);
  }
  free(a);

  return 1;
}