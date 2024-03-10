#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<int,int> m;

vector<int> getvector(int n){
  vector<int> v(n+1);
  for(int i = 0 ; i < n ; i++){
    int x;
    cin >> x;
    v[i] = x;
  }
  return v;
}

int find_maxmoney(int n,vector<int> v_v,vector<int> v_e){
  for(int i = 0 ; i <= n ; i++){
    int a = m[i-1];
    int b = m[i-2];
    int c = m[i-3];
    int d = m[i-4];
    if(v_e[i] == 1){
      m[i] = max({a,b,c,d}) + v_v[i];
      m[i-1] = m[i];
      m[i-2] = m[i];
      m[i-3] = m[i];
      m[i-4] = m[i];
    }else{
      m[i] = max({a,b,c,d}) + v_v[i];
    }
  }
  return m[n];
}

int main() {
  int n;
  cin >> n;
  vector<int> v_v = getvector(n);
  v_v[n] = 0;
  vector<int> v_e = getvector(n);
  v_e[n] = 0;
  cout << find_maxmoney(n,v_v,v_e) << endl;
}



/*
5
-1 -1 -2 -1 -3
0 0 0 0 0

7
-1 -10 -5 -5 -5 -5 -5
0 1 0 0 0 0 0
*/