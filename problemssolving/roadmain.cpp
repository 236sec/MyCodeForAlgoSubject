#include <iostream>
#include <list>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 100010

vector<int> parent(MAX_N);
vector<int> groupam(MAX_N);
struct Element {
  int node;
  int weight;
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
  int n, m;
  cin >> n >> m;
  init_parent(n);
  vector<pair<int,int>> pair_node;
  vector<pair<int,int>> edsort;
  for (int i = 0; i < m; i++) {
    int a, b, c,status;
    cin >> a >> b >> c >> status;
    a--;
    b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
    if(status == 1){
      if(find(a) != find(b)){
        union_parent(a,b);
      }
    }else{
      pair_node.push_back({a,b});
      int id = pair_node.size() - 1;
      edsort.push_back({c,id});
    }
  }
  sort(edsort.begin(),edsort.end());
  int weight = 0;
  for (int i = 0; i < edsort.size() ; i++) {
    int id = edsort[i].second;
    int u = pair_node[id].first;
    int v = pair_node[id].second;
    if(find(u) != find(v)){
      union_parent(u,v);
      weight += edsort[i].first;
    }
  }
  cout << weight;
}

/*
5 6
1 3 5 1
1 2 8 1
2 4 3 0
3 4 6 0
5 3 7 1
5 4 1 1

*/