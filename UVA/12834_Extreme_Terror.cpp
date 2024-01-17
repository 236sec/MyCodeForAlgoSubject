#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 0 ; i < t ; i++){
    int n,k;
    cin >> n >> k;
    vector<long long> xi(n);
    for(int j = 0 ; j < n ; j++){
      long long x;
      cin >> x;
      xi[j] = x;
    }
    vector<long long> v(n);
    for(int j = 0 ; j < n ; j++){
      long long y;
      cin >> y;
      v[j] = y-xi[j];
    }
    sort(v.begin(),v.end());
    long long profit = 0;
    for(int j = 0 ; j < n ; j++){
      //cout << v[j] << endl;
      if(k>0 && v[j] < 0){
        k--;
        continue;
      }
      profit += v[j];
    }
    if(profit > 0){
      cout << "Case " << i+1 << ": " << profit << endl;
    }else{
      cout << "Case " << i+1 << ": " << "No Profit" << endl;
    }
    
  }
}

/*
2
5 2
4 5 6 7 8
5 6 7 8 9
5 0
7 6 7 8 7
4 5 6 7 8


*/
