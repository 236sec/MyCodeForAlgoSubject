#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
map<int,int> table;
int memo[27][27][1010]; // Memoization table


int opt(int i,int j,int l,string &x){
  if(l>=x.length()){
    return 0;
  }
  if (memo[i - 'A'][j - 'A'][l] != -1) {
        return memo[i - 'A'][j - 'A'][l];
    }
  int num = (int)x[l];
  //cout << x[l] << " " << num << endl;
  int rol = min((i-num+26)%26,(num-i+26)%26);
  int ror = min((j-num+26)%26,(num-j+26)%26);
  int result = min(rol+opt(num,j,l+1,x),ror+opt(i,num,l+1,x));
  memo[i - 'A'][j - 'A'][l] = result;
  return result;
}

int main() {
  // A-Z 65 - 90
  int t;
  cin >> t;
  memset(memo, -1, sizeof(memo));
  for(int k = 0 ; k < t ; k++){
    string x;
    cin >> x;
    memset(memo, -1, sizeof(memo));
    cout << opt(65,65,0,x) << endl;
  }
}

/*
3
BYEBYE
YOUBELONGWITHME
HELLOWORLD
*/