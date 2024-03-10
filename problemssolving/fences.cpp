#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100009

struct Element {
  int s;
  int e;
  friend bool operator<(const Element& l, const Element& r)
  {
      if (l.s != r.s) {
          return l.s < r.s;
      } else {
          return l.e < r.e;
      }
  }
};

pair<int,Element> v[MAX_N];

void getvector(int n){
  for(int i = 0 ; i < n ; i++){
    int s,e;
    cin >> s >> e;
    v[i].second.s = s;
    v[i].second.e = e;
    v[i].first = s;
  }
  return ;
}

int main(){
  int n,l;
  cin >> n >> l;
  getvector(n);
  sort(v,v+n);
  int cover = 0;
  int count = 0;
  for(int i = 0 ; i < n ; i++){
    if(cover < v[i].second.e){
      cover = v[i].second.s+l;
      count++;
    }
    //cout << v[i].second.d << " ";
  }
  cout << count;
}

/*
3 10
3 6
8 10
15 19

4 10
3 6
8 10
10 14
18 22
*/