#include <stdio.h>
#include <string.h>
#define MAX_LENTH 100

int charToNum(char a){
  int result = a - '0';
  return result;
}


int mainasdasd(void){
  char x[MAX_LENTH];
  char y[MAX_LENTH];
  
  scanf("%s\n",x);
  scanf("%s",y);
  int result = 0;
  int length;
  int length_x = strlen(x);
  int length_y = strlen(y);
  if(length_x >= length_y){
    length = length_x;
  }else{
    length = length_y;
  }
  char strResult[length+1];
  strResult[0] = 0;
  for(int i = 0 ; i < length ; i++){
    if(i < length_x && i < length_y){
      result += charToNum(x[length_x-i-1]) + charToNum(y[length_y-i-1]);
    }else if(i<length_x){
      result += charToNum(x[length_x-i-1]);
    }else{
      result += charToNum(y[length_y-i-1]);
    }
    if(result >= 10){
      strResult[length-i] = result%10;
      if(length-i-1 >= 0){
        result /= 10;
      }else{
        strResult[0] = result/10;
      }
    }else{
      strResult[length-i] = result;
      result = 0;
    }
  }
  if (result!=0){
    strResult[0]=result;
  }
  int found_num = 0;
  for(int i = 0 ; i < length+1 ; i++){
    if(strResult[i] != 0 || found_num){
      found_num = 1;
      printf("%d",strResult[i]);
    }
  }
  return 1;
}
