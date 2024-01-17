#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 100009

int main() {
  int n, d, r;
  while (true) {
    cin >> n >> d >> r;
    if (n == 0 && d == 0 && r == 0) {
      break;
    }
    int m[n];
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> m[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(m,m+n);
    sort(a,a+n,greater<int>());
    int cost = 0;
    for (int i = 0; i < n; i++) {
      int miles = m[i] + a[i];
      if(miles > d){
        cost += (miles - d) * r;
      }
    }
    cout << cost << endl;
  }
}

/*
2 20 5
10 15
10 15
2 20 5
10 10
10 10
0 0 0

16 8772 2
2640 1550 4569 8454 1619 1851 6227 7661 7358 4083 2809 4038 6815 7715 8287 2406
7073 1582 1852 5283 682 4079 5312 4624 9252 9885 358 7055 1611 9568 6662 7954
50 2564 4
*/
