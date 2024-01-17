#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 100009

int main() {
  int c;
  cin >> c;
  int ans = 0;
  vector<int> v;
  for(int i = 0 ; i < c ; i++){
    ans = 0;
    int n,h,ta,td;
    cin >> n >> h >> ta >> td;
    for(int i = 0 ; i < n ; i++){
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(),v.end());
    if(td < 2*ta){
      int count = 0;
      int start_pos = 0;
      for(int i = 0 ; i < n ; i++){
        if(start_pos > n-i-1){
          //cout << "Break at " << start_pos << " " << n-i-1 << endl;
          break;
        }
        if(start_pos == n-i-1){
          break;
        }
        if(v[start_pos] + v[n-i-1] < h){
          //cout << "Add " << v[start_pos] << " " << v[n-i-1] << endl;
          start_pos++;
          count++;
        }
      }
      //cout << "Not add " << n-2*count << endl;
      ans += count*td;
      ans += (n-2*count) * ta;
    }else{
      ans = ta*n;
    }
    cout << "Case " << i+1 << ": " << ans << endl;
    v.clear();
  }
}

/*
5
7 6 2 3
1 2 3 4 5 6 7
7 6 2 3
7 6 5 4 3 2 1
7 6 2 3
1 5 2 4 3 7 6
7 8 2 3
1 2 3 4 5 6 7
7 8 2 4
1 2 3 4 5 6 7

*/
