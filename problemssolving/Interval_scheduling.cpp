#include <iostream>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int,int> m;
  int min_num = 2000100;
  for(int i = 0 ; i < n ; i++){
    int a,b;
    cin >> a >> b;
    if(m[b] == 0){
      m[b] = a;
    }else{
      if(m[b] < a){
        m[b] = a;
      }
    }
    if(b < min_num){
      min_num = b;
    }
  }
  int count = 1;
  int startat = m[min_num];
  int endat = min_num;
  int endatvalid = endat;
  //cout << startat << " " << endat << endl;
  for(int i = 0 ; i < n ; i++){
    auto ne = next(m.lower_bound(endat));
    if(ne == m.end()){
      break;
    }
    //cout << (++m.lower_bound(endat))->second << " " << (++m.lower_bound(endat))->first << endl;
    startat = ne->second;
    endat = ne->first;
    if(startat < endatvalid){
      continue;
    }
    endatvalid = ne->first;
    count++;
    //cout << i->second << " " << i->first << endl;
  }
  cout << count << endl;
}

/*
3
1 2 
2 3
1 3

4
1 2
1 4
3 4
2 4

6
1 2
2 3
3 4
1 5
7 8
8 9

*/