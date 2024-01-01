#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
  set<int, less<int> > s;
  map<int,int> ma;
  int n,m;
  cin >> n >> m;
  int sum = 0;
  for(int i = 0 ; i < n ; i++){
    int x;
    cin >> x;
    sum += x;
    s.insert(sum);
    ma[sum] = i+1;
  }
  //cout << endl;
  for(int i = 0 ; i < m ; i++){
    int y;
    cin >> y;
    auto k = s.lower_bound(y);
    auto z = k;
    z--;
    if(k == s.end()){
      int result;
      if(y >= *--s.end()){
        result = ma[*--s.end()];
      }else{
        result = 0;
      }
      cout << result << endl;
    }else{
      int result;
      if(*k == y){
        result = ma[*k];
      }else{
        result = ma[*z];
      }
      cout << result << endl;
    }
    
  }
}
/*
3 3
10
20
30
15
30
7

*/