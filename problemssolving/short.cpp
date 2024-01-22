#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<int> v(n);
  map<int,int> m;
  map<int,int> indm;
  int min_value = 1000000001;
  for(int i = 0 ; i < n ; i++){
    int x;
    cin >> x;
    v[i] = x;
    if(x < min_value){
      if(min_value != 1000000001){
        indm[min_value] = i;
      }
      min_value = x;
    }
    m[i] = min_value;
  }
  for(int i = 0 ; i < q ; i++){
    int t,x;
    cin >> t >> x;
    if(t == 1){
      cout << m[x-1] << endl;
    }
    if(t == 2){
      auto it = indm.lower_bound(x);
      if(x > v[0]){
        cout << 0 << endl;
      }else if(x <= m[n-1]){
        cout << n << endl;
      }else if(it != indm.end()){
        //cout << "Querry : " << x << " Bound : " << it->first << endl;
        cout << it->second << endl;
      }else{
        cout << n << endl;
      }
    }
  }
}

/*
5 8
100
240
80
90
75
1 1
2 95
1 4
2 80
2 50
1 5
2 120
2 100

*/
