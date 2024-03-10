#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

struct Element {
  int c;
  int p;
  int w;
};

void create_struct(int k , int n ,vector<Element> &v,list<int> &l){
  for(int i = 0 ; i < k ; i++){
    int c,p,w;
    cin >> c >> p >> w;
    v.push_back({c,p,w});
  }
  /*
  for(auto i = v.begin() ; i != v.end() ; i++){
    cout << i->c << " " << i->p << " " << i->w << endl;
  }
  */
  for(int i = 0 ; i < n ; i++){
    int tmp;
    cin >> tmp;
    l.push_back(tmp);
  }
}

int find_num(list<int> &l,int w){
  auto pos = l.begin();
  int wnow = 0;
  int round = 1;
  while(pos != l.end()){
    if(wnow + *pos <= w){
      wnow += *pos;
      pos++;
    }else{
      wnow = 0;
      round++;
    }
    if(wnow == 0 && *pos > w){
      return -1;
    }
  }
  return round;
}

int main() {
  int k,n;
  cin >> k >> n;
  vector<Element> v;
  list<int> l;
  create_struct(k,n,v,l);
  set<int> sol;
  for(auto i = v.begin() ; i != v.end() ; i++){
    //cout << find_num(l, i->w) << endl;
    int round = find_num(l, i->w);
    if(round != -1){
      int cost = i->c + round*i->p;
      sol.insert(cost);
    }
  }
  cout << *sol.begin() << endl;
}

/*
4 6
50 100 20 
100 10 10 
0 1000 1000 
10 10 5 
5 4 3 3 3 7

*/