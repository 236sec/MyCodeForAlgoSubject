#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100009

struct Element {
  int d;
  int c;
  friend bool operator<(const Element& l, const Element& r)
  {
      if (l.d != r.d) {
          return l.d < r.d;
      } else {
          return l.c < r.c;
      }
  }
};

pair<int,Element> v[MAX_N];

void getvector(int n){
  for(int i = 0 ; i < n ; i++){
    int d,c;
    cin >> d >> c;
    v[i].second.d = d;
    v[i].second.c = c;
    v[i].first = d;
  }
  return ;
}

int main(){
  int n;
  cin >> n;
  getvector(n);
  sort(v,v+n);
  int max_late = 0;
  int day = 0;
  for(int i = 0 ; i < n ; i++){
    day += v[i].second.c;
    if(day - v[i].second.d - 10 > max_late){
      max_late = day - v[i].second.d - 10;
    }
    //cout << v[i].second.d << " ";
  }
  cout << max_late*1000;
}

/*
3
50 10
20 20
10 30

3
50 10
20 10
10 20
*/