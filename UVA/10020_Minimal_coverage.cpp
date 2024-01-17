#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define MAX_N 100009

struct val {
  int s;
  int e;
  friend bool operator<(const val& l, const val& r)
  {
      if (l.s != r.s) {
          return l.s < r.s;
      } else {
          return l.e > r.e;
      }
  }
};

pair<int, val> v[MAX_N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    int count = -1;
    while (true) {
      count++;
      int x, y;
      cin >> x >> y;
      if (x == 0 && y == 0) {
        break;
      }
      v[count].first = x;
      v[count].second.s = x;
      v[count].second.e = y;
    }
    sort(v, v + count);
    /*
    for (int i = 0; i < count; i++) {
      cout << v[i].second.s << " " << v[i].second.e << endl;
    }
    */
    int length_cover = 0;
    int max_far = 0;
    int max_start = 0;
    vector<pair<int,int>> sol;
    for(int i = 0 ; i < count ; i++){
      if(length_cover >= m){
        break;
      }
      //cout << "Checking " << v[i].second.s << " " << v[i].second.e << " Cover : " << length_cover << endl;
      if(v[i].second.s <= length_cover){
        if(max_far < v[i].second.e){
          max_far = v[i].second.e;
          max_start = v[i].second.s;
        }
      }else{
        if(max_far != 0 || max_start != 0){
          sol.push_back(make_pair(max_start,max_far));
          length_cover = max_far;
          max_far = 0;
          max_start = 0;
          i--;
        }
      }
    }
    if(length_cover < m){
      if(max_far != 0 || max_start != 0){
        sol.push_back(make_pair(max_start,max_far));
        length_cover = max_far;
      }
    }
    if(sol.size() == 0 || length_cover < m){
      cout << "0" << endl;
    }else{
      cout << sol.size() << endl;
      for(auto i = sol.begin() ; i != sol.end() ; i++){
        cout << i->first << " " << i->second << endl;
      }
    }
    sol.clear();
    cout << endl;
  }
}

/*
2

23
-10 5
37 51
-18 -13
-2 17
47 57
1 7
15 27
10 23
40 58
22 39
-19 -18
25 34
-20 5
35 58
-5 5
-16 0
-11 -2
0 0

37
57 63
15 26
67 69
31 39
39 63
56 81
-9 2
7 29
-11 11
47 51
-20 1
19 26
50 54
14 33
0 0
*/
