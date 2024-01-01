#include <stdio.h>
#include <stdlib.h>

void printlist(int* li ,int n){
  for(int i = 0 ; i < n ; i++){
    printf("%d ",li[i]);
  }
  printf("\n");
}

void insertion_sort(int* li , int n){
  char tmp;
  for(int i = 1 ; i < n ; i++){
    for(int j = i ; j > 0 ; j--){
      if(li[j] < li[j-1] ){
        tmp = li[j-1];
        li[j-1] = li[j];
        li[j]=tmp;
      }
      else{
        break;
      }
    }
    // printf("%d\n",li);
    printlist(li,n);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  int* li = (int*)malloc(sizeof(int) * n);
  int tmp;
  for (int i = 0; i < n; i++) {
    scanf("%d",&tmp);
    li[i] = tmp;
  }
  insertion_sort(li,n);
  free(li);
  return 0;
}