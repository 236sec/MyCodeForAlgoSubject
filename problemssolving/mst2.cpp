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
  vector<pair<int,int>> pair_node(m);
  vector<pair<int,int>> edsort(m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
    pair_node[i] = {a,b};
    edsort[i] = {c,i};
  }
  sort(edsort.begin(),edsort.end());
  int weight = 0;
  for (int i = 0; i < m; i++) {
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
4 5
1 2 10
1 3 20
3 4 5
4 2 7
2 3 12

*/