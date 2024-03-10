#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, int> m;

int max_coin(int n, vector<int> &v) {
  //cout << n << endl;
  if (m.find(n) != m.end()) {
    return m[n];
  }
  int a = max_coin(n-1,v);
  int b = max_coin(n-2,v);
  int c = max_coin(n-3,v)+v[n-1];
  int result = max({a,b,c});
  m[n] = result;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = x;
  }
  m[1] = 0;
  m[2] = 0;
  m[3] = v[2];
  max_coin(n,v);
  // for(auto i = m.begin() ; i != m.end() ; i++){
  //   cout << i->second << " ";
  // }
  //cout << endl;
  cout << m[n] << endl;
}

/*
12
1 2 5 4 3 0 6 1 2 7 2 1

*/