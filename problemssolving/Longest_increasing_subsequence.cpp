#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int,pair<int,int>> m;

int max_length(int n,vector<int> &v){
  if(m.find(n) != m.end()){
    return m[n].first;
  }
  if(n == 0){
    pair<int,int> p = make_pair(1,-1);
    m[0] = p;
    return 1;
  }
  int max = 0;
  int last_num = -1;
  for(int i = 0 ; i < n ; i++){
    int l = max_length(i,v);
    if(max<l && v[i] < v[n]){
      last_num = i;
      max = l;
    }
  }
  m[n] = {max+1,last_num};
  return max+1;
}

void print_seq(int n,vector<int> &v){
  if(n == -1){
    return;
  }
  print_seq(m[n].second,v);
  cout << v[n] << " ";
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0 ; i < n ; i++){
    int x;
    cin >> x;
    v[i] = x;
  }
  max_length(n-1,v);
  int max_num = 0;
  int start_pos = 0;
  for(auto i = m.begin() ; i != m.end() ; i++){
    if(i->second.first > max_num){
      max_num = i->second.first;
      start_pos = i->first;
    }
  }
  cout << max_num << endl;
  print_seq(start_pos,v);
  
}

/*
5 1 2 2 3 4
output:
4 
1 2 3 4

5 5 4 3 2 1
output: 
1 
1

5 1 1 1 1 1
output: 
1 
1
*/
