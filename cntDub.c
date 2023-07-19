#include <stdio.h>

int findNum(int num_in , int arrayNum[] ,int nEle){
  if(nEle == 0 ){
    return -1;
  }
  for(int i = 0 ; i < nEle ; i++){
    if(num_in == arrayNum[i]){
      return i;
    }
  }
  return -1;
}

int find_maxcount(int arrayCount[],int nEle){
  int max_value = -1;
  for(int i = 0 ; i < nEle ; i++){
    if(arrayCount[i] > max_value){
      max_value = arrayCount[i];
    }
  }
  return max_value;
}

int maitasdn(void){
  int rounds;
  scanf("%d\n",&rounds);
  int arrayNum[rounds];
  int arrayCount[rounds];
  int nsign_value = 0;
  int size = sizeof(arrayNum)/sizeof(arrayNum[0]);
  for(int i = 0 ; i < rounds ; i++){
    int num_in;
    scanf("%d",&num_in);
    int index_found = findNum(num_in, arrayNum , nsign_value);
    if(index_found != -1){
      arrayCount[index_found]++;
    }else{
      arrayNum[nsign_value] = num_in;
      arrayCount[nsign_value]=1;
      nsign_value++;
    }
  }
  int max_count = find_maxcount( arrayCount , nsign_value);
  int array_out[size];
  int sign_valu = 0;
  for(int i = 0 ; i < size ; i++){
    if(arrayCount[i] == max_count){
      array_out[sign_valu] = arrayNum[i];
      sign_valu++;
    }
  }
  for(int i = 0 ; i < sign_valu ; i++){
    int min_valu = 101;
    int at = -1;
    for(int y = 0 ; y < sign_valu ; y++){
      if(array_out[y]<min_valu){
        min_valu = array_out[y];
        at = y;
      }
    }
    array_out[at] = 101;
    printf("%d ",min_valu);
  }
  return 0;
}