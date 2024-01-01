#include <stdio.h>
#include <math.h>

int isPrime(int num){
  int i;
  int range = sqrt((double)num);  //O(1)
  for(i=2 ; i<=range ; i++){       //call 2,3,...,sqrt(n)
    if(num%i==0){
      return 0;
    }
  }
  return 1;
}

int main(void){
  int num;
  scanf("%d",&num);
  printf("%d\n",isPrime(num));
  return 1;
}

// O(sqrt(n))