#include <stdio.h>
#include <stdlib.h>

void findStats(int* nums,int n,int* maxi,int* mini,double* avg) {
  int sum_result = 0;
  int max_num = 0;
  int min_num = 101;
  for(int i = 0 ; i < n ; i++){
    sum_result+=nums[i];
    if(nums[i]>max_num){
      max_num = nums[i];
    }
    if(nums[i]<min_num){
      min_num = nums[i];
    }
  }
  *mini = min_num;
  *maxi = max_num;
  *avg = (double)sum_result/n;
}


int mainttt() {
  int n, i, maxi, mini;
  double avg;
  int *nums;
  scanf("%d", &n);
  nums = (int *)malloc(sizeof (int) *n);
  for (i=0; i<n; i++)
  scanf("%d", nums+i);
  findStats(nums,n,&maxi,&mini,&avg);
  printf("%.2f %d %d", avg, maxi, mini);
  free(nums);
  return 0;
}