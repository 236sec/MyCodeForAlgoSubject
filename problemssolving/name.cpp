#include <iostream>
#include <map>
#include <string>
using namespace std;
string s;
string check;

int main() {
  cin >> s;
  cin >> check;
  //for (auto i = s.begin(); i != s.end(); i++) {
    //cout << *i;
  //}
  //cout << endl;
  int start = 0;
  int end = s.size();
  // cout << end << endl;
  int count = 0;
  for (auto i = check.begin(); i != check.end(); i++) {
    if (start == end) {
      start = 0;
    }
    if (s[start] == *i) {
      //cout << *i;
      count++;
      start++;
    }
  }
  //cout << endl;
  cout << count/s.size();
}

/*
pracha
thisisprachaheyproactivehappypramotechanochanell

*/