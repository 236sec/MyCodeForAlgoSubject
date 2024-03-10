#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
#define MAX_N 100010

vector<int> parent(MAX_N);
vector<int> groupam(MAX_N);
struct Element {
  int node;
  double weight;
};
vector<list<Element>> adj(MAX_N);


void init_parent(int n){
  for(int i = 0 ; i < n ; i++){
    parent[i] = i;
    groupam[i] = 1;
  }
}

int find(int x){
  if(parent[x] == x){
    return x;
  }else{
    return find(parent[x]);
  }
}

void union_parent(int x , int y){
  int a = find(x);
  int b = find(y);
  if(a == b){
    return;
  }
  if(groupam[a] > groupam[b]){
    parent[b] = a;
    groupam[a] += groupam[b];
  }else{
    parent[a] = b;
    groupam[b] += groupam[a];
  }
}

int main() {
  int n;
  cin >> n;
  init_parent(n);
  vector<pair<int,int>> pair_node;
  vector<pair<double,int>> edsort;
  vector<pair<int,int>> n_point(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    n_point[i] = {x,y};
  }
  int count = 0;
  for(int i = 0 ; i < n ; i++){
    for(int j = i+1 ; j < n ; j++){
      int ax = n_point[i].first;
      int ay = n_point[i].second;
      int bx = n_point[j].first;
      int by = n_point[j].second;
      //cout << ax << " " << ay << " " << bx << " " << by << endl;
      double c = sqrt(pow(ax-bx,2)+pow(ay-by,2));
      //cout << c << endl;
      adj[i].push_back({j,c});
      adj[j].push_back({i,c});
      pair_node.push_back({i,j});
      edsort.push_back({c,count});
      count++;
    }
  }
  sort(edsort.begin(),edsort.end());
  /*
  for(auto i = edsort.begin() ; i != edsort.end() ; i++){
    cout << i->first << " " << i->second << endl;
  }
  */
  double weight = 0;
  double lastadd = 0;
  for (int i = 0; i < count; i++) {
    int id = edsort[i].second;
    int u = pair_node[id].first;
    int v = pair_node[id].second;
    if(find(u) != find(v)){
      union_parent(u,v);
      weight += edsort[i].first;
      lastadd = edsort[i].first;
      //cout << edsort[i].first << endl;
    }
  }
  cout << fixed << setprecision(4) << weight - lastadd << endl;
}

/*
7
2 2
8 2
9 3
4 3
10 1
3 5
4 4


*/