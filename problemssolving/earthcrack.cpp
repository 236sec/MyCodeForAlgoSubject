#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 1100000 
#define MAX_N 550
map<pair<int,int>,int> table;
vector<vector<int>> v(MAX_N,vector<int> (MAX_N));


int opt(int i, int j,int m,int n){
  if(i>=m){
    return 0;
  }
  if(j >=n){
    return MAX_NUM;
  }
  if(j<0){
    return MAX_NUM;
  }
  if(table.find({i,j}) != table.end()){
    return table[{i,j}];
  }
  int result = MAX_NUM;
  for(int k = j-1 ; k < j+2 ; k++){
    result = min(result,v[i][j]+opt(i+1,k,m,n));
  }
  table[{i,j}] = result;
  return result; 
}

int main() {
  int t;
  cin >> t;
  for(int k = 0 ; k < t ; k++){
    int m,n;
    cin >> m >> n;
    for(int i = 0 ; i < m ; i++){
      for(int j = 0 ; j < n ; j++){
        int x;
        cin >> x;
        v[i][j] = x;
      }
    }
    int ans = MAX_NUM;
    for(int j = 0 ; j < n ; j++){
      ans = min(ans,opt(0,j,m,n));
    }
    table.clear();
    cout << ans << endl;
  }
}

/*

3
8 5
1 6 7 2 3 
7 9 5 2 1 
1 1 8 8 6 
6 5 6 3 9 
9 1 4 8 6 
4 2 9 7 7 
2 3 2 5 8 
5 8 2 4 4 
10 10
3 7 8 8 9 8 5 3 2 4 
4 3 9 3 9 1 9 6 1 2 
7 5 2 5 8 1 1 9 6 5 
8 6 4 3 6 7 5 9 1 4 
5 3 9 5 8 2 9 8 1 3 
7 2 4 6 8 4 9 4 1 5 
2 7 1 5 8 8 2 2 1 5 
4 2 4 9 6 4 3 7 9 5 
6 3 3 6 6 2 6 3 9 4 
5 1 1 1 1 3 4 1 3 6
1 1
1000000

output:
20
19
1000000
*/
