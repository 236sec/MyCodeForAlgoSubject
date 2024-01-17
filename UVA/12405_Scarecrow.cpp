#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 109

int main() {
  int c;
  cin >> c;
  vector<char> v(MAX_N);
  for (int i = 0; i < c; i++) {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      char tmp;
      cin >> tmp;
      v[j] = tmp;
    }
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (v[j] == '.') {
        if (j + 1 < n) {
          count++;
          j += 2;
          continue;
        }
        if (j - 1 >= 0) {
          count++;
        }
      }
    }
    v.clear();
    cout << "Case " << i + 1 << ": " << count << endl;
  }
}

/*


*/
