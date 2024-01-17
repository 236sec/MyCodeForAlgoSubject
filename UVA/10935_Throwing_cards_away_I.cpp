#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
  int n;
  while(cin >> n){
    if(n == 0){
      return 0;
    }
    vector<int> v;
    for(int i = 0 ; i < n ; i++){
      v.push_back(0);
    }
    int i = 0;
    int step = 0;
    int count = 0;
    cout << "Discarded cards:";
    while( count != n-1 ){
      if(i >= n){
        i = i % n;
      }
      if(!v[i]){
        if(step == 0 || step == 2){
          count++;
          v[i] = 1;
          step = 0;
          if(count == n-1){
            cout << " " << i+1;
          }else{
            cout << " " << i+1 << ",";
          }
        }
        step++;
      }
      i++;
    }
    cout << endl;
    for( int i = 0 ; i < n ; i++){
      if(v[i] == 0){
        cout << "Remaining card: " << i+1 << endl;
      }
    }
  }
}
