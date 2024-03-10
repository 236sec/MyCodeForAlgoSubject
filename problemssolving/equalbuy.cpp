#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int memo[210][310][310];


int opt(int i,int c1,int c2,vector<int> &v){
  if(i==0){
    if(c1 == c2){
      return 0;
    }else{
      return -310;
    }
  }
  if(memo[i][c1][c2] != -1){
    return memo[i][c1][c2];
  }
  //cout << v[i]+opt(i-1,c1-v[i],c2,v) << " " <<opt(i-1,cost,v) << endl;
  int result = max({v[i]+opt(i-1,c1-v[i],c2,v),v[i]+opt(i-1,c1,c2-v[i],v),opt(i-1,c1,c2,v)});
  memo[i][c1][c2] = result;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n+1);
  v[0] = 0;
  int sum = 0;
  for(int i = 1 ; i <= n ; i++){
    int x;
    cin >> x;
    v[i] = x;
    sum+=x;
  }
  memset(memo, -1, sizeof(memo));
  int ans = opt(n,0,0,v)/2;
  if(ans < 0){
    cout << 0 << endl;
  }else{
    cout << ans << endl;
  }
}

/*
5
5
7
9
3
11

4
1
10
50
100
*/