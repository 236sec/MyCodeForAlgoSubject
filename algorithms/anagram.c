#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printlist(char** li ,int n){
  for(int i = 0 ; i < n ; i++){
    printf("%s ",li[i]);
  }
  printf("\n");
}

void insertion_sort_str(char* li , int n){
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
    // printf("%s\n",li);
  }
}

int main(void) {
  int n,ch;
  scanf("%d %d", &n,&ch);
  char** ori_li = (char**)malloc(sizeof(char*) * n);
  char** li = (char**)malloc(sizeof(char*) * n);
  for (int i = 0; i < n; i++) {
    char* tmp1 = (char *)malloc(sizeof(char) * 51);
    char* tmp2 = (char *)malloc(sizeof(char) * 51);
    scanf("%s",tmp1);
    strcpy(tmp2,tmp1);
    ori_li[i] = tmp1;
    li[i] = tmp2;
  }
  for (int i = 0; i < n; i++) {
    insertion_sort_str(li[i],strlen(li[i]));
  }
  // printlist(li,n);
  char* tmp = (char *)malloc(sizeof(char) * 51);
  for(int i = 0 ; i < ch ; i++){
    scanf("%s",tmp);
    insertion_sort_str(tmp,strlen(tmp));
    for(int j = 0 ; j < n ; j++){
      if(!strcmp(li[j],tmp)){
        printf("%s ",ori_li[j]);
      }
    }
    printf("\n");
  }
  free(li);
  free(ori_li);
  return 0;
}