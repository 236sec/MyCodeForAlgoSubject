#include <stdio.h>
#include <stdlib.h>

void print_pattern_one(int n){
  for(int row = 0 ; row < n ; row++){
    for(int i = 0 ; i < n ; i++){
      printf("%d ",(1+row)+n*i);
    }
    printf("\n");
  }
}

void print_pattern_two(int n){
  for(int row = 0 ; row < n ; row++){
    for(int i = 0 ; i < n ; i++){
      if(i%2==0){
        printf("%d ",1+n*(i)+row);
      }else{
        printf("%d ",n*(i+1) - row);
      }
    }
    printf("\n");
  }
}

void print_pattern_three(int n){
  int **a=NULL;
  int row = n,col = n;
  a = (int **)malloc(sizeof(int *) * row);
  //create array
  for(int i = 0 ; i < row ; i++){
    a[i] = (int *)malloc(sizeof(int)*col);
    for(int j = 0 ; j < col ; j++){
      a[i][j] = 0;
    }
  }

  //first half
  int summing = 1;
  int isdefault = 1;
  for(int time = 0 ; time < n ; time++){
    if(isdefault==1){
      for(int j=0 ; j<time+1 ; j++){
        a[row-1-j][time-j] = summing;
        summing++;
        isdefault=0;
      }
    }else{
      for (int j = 0; j < time+1; j++) {
        a[row-time-1+j][j] = summing;
        summing++;
        isdefault=1;
      }
    }
  }

  //second half
  int end_with = isdefault; 
  for(int time = 0 ; time < n-1 ; time++){
    for(int j = 0 ; j < n-1-time ; j++){
      if(isdefault==1){
        a[row-2-time-j][col-1-j] = summing;
        summing++;
      }else{
        a[0+j][1+j+time] = summing;
        summing++;
      }
    }
    if(isdefault==1){
      isdefault=0;
    }else{
      isdefault=1;
    }
  }
  
  
  // print array
  for(int i = 0 ; i < row ; i++){
    for(int j = 0 ; j < col ; j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  
  for(int i = 0 ; i < row ; i++){
    free(a[i]);
  }
  free(a);
  
}

void print_pattern_four(int n){
  int **a=NULL;
  int row = n,col = n;
  a = (int **)malloc(sizeof(int *) * row);
  //create array
  for(int i = 0 ; i < row ; i++){
    a[i] = (int *)malloc(sizeof(int)*col);
    for(int j = 0 ; j < col ; j++){
      a[i][j] = 0;
    }
  }

  //set first col
  int summing = 1;
  for(int i = 0 ; i < n ; i++){
    a[i][0] = summing;
    summing++;
  }
  int j_s = 0;
  int i_s = n-1;
  int first = 1;
  for(int round = 0 ; round < (n-1) ; round++){
    for(int j = 0 ; j < n-1-round ; j++){
      if(first){
        j_s+=1;
      }else{
        j_s-=1;
      }
      a[i_s][j_s] = summing;
      summing++;
    }

    for(int i = 0 ; i < n-1-round ; i++){
      if(first){
        i_s-=1;
      }else{
        i_s+=1;
      }
      a[i_s][j_s] = summing;
      summing++;
    }
    if(first){
        first = 0;
      }else{
        first = 1;
      }
  }
  
  // print array
  for(int i = 0 ; i < row ; i++){
    for(int j = 0 ; j < col ; j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  
  for(int i = 0 ; i < row ; i++){
    free(a[i]);
  }
  free(a);
  
}

int maintttt(void){
  int n,pattern;
  scanf("%d %d",&n,&pattern);
  if(pattern==1) print_pattern_one(n);
  if(pattern==2) print_pattern_two(n);
  if(pattern==3) print_pattern_three(n);
  if(pattern==4) print_pattern_four(n);
  
  return 1;
}