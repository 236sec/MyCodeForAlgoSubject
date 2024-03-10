#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
map<pair<int,int>,int> m;
string x;
string y;

void print_sequnce(int i, int j){
  int value = m[{i,j}];
  if(value == 0){
    return;
  }
  //cout << i << " " << j << endl;
  if(value-1==m[{i-1,j-1}] && x[i] == y[j]){
    print_sequnce(i-1,j-1);
    cout << x[i];
    return;
  }
  if(value==m[{i-1,j-1}]){
    print_sequnce(i-1,j-1);
    return;
  }
  if(value==m[{i-1,j}]){
    print_sequnce(i-1,j);
    return;
  }
  if(value==m[{i,j-1}]){
    print_sequnce(i,j-1);
    return;
  }
}

int opt(int i , int j){
  if(i==-1 || j==-1){
    m[{i,j}] = 0;
    return 0;
  }
  if(m.find({i,j}) != m.end()){
    return m[{i,j}];
  }
  //cout << x[i] << " " << y[j] << endl;
  int cost = 0;
  if(x[i] == y[j]){
    cost = 1;
  }
  int result = max({opt(i-1,j),opt(i,j-1),cost+opt(i-1,j-1)});
  m[{i,j}] = result;
  return result;
}

int main() {
  cin >> x;
  cin >> y;
  cout << opt(x.length()-1,y.length()-1) << endl;
  print_sequnce(x.length()-1,y.length()-1);
}

/*
AABBCDEF
ABECEF
output:
5
ABCEF


AAABBBABCABC
AABACABCEDF
output:
8
AABACABC
*/
