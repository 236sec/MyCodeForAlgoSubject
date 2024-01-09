#include <iostream>
#include <vector>
#include <list>
using namespace std;
#define MAX_N 100009

vector<list<int>> adj(MAX_N);

void print_layer(vector<int> layers){
  for(int i = 0; i < layers.size(); i++){
    cout << i << " : " << layers[i] << endl;
  }
}

void bfs(int s,vector<bool> &visited,vector<int> &layers){
  list<int> sta;
  sta.push_back(s);
  int layer = 0;
  layers[s] = 0;
  while(!sta.empty()){
    int nnode = sta.size();
    layer++;
    for(int i = 0 ; i < nnode ; i++){
      int node = sta.front();
      visited[node] = 1;
      for(auto j = adj[node].begin(); j != adj[node].end(); j++){
        if(visited[*j] == 0){
          visited[*j] = 1;
          layers[*j] = layer;
          sta.push_back(*j);
        }
      }
      sta.pop_front();
    }
  }
  return ;
}

bool isbipartite(int s,vector<bool> &visited,vector<int> &groups){
  list<int> sta;
  sta.push_back(s);
  int layer = 0;
  groups[s] = 0;
  while(!sta.empty()){
    int nnode = sta.size();
    layer++;
    for(int i = 0 ; i < nnode ; i++){
      int node = sta.front();
      visited[node] = 1;
      for(auto j = adj[node].begin(); j != adj[node].end(); j++){
        if(visited[*j] == 0){
          visited[*j] = 1;
          groups[*j] = 1-groups[node];
          sta.push_back(*j);
        }else if(groups[*j] == groups[node] && visited[*j] == 1){
          return false;
        }
      }
      sta.pop_front();
    }
  }
  return true;
}

int dfs(int s,int d,vector<bool> &visited){
  if(visited[s] == 1){
    return 0;
  }
  // cout << s << " ";
  visited[s] = 1;
  if(s == d){
    // cout << "YES" << endl;
    return 1;
  }
  for(auto i = adj[s].begin() ; i != adj[s].end() ; i++){
    if(dfs(*i,d,visited)){
      return 1;
    }
  }
  return 0;
}

int main(){
  int n,m;
  cin >> n >> m;
  for(int i = 0 ; i < m ; i++){
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int s = 1;
  int d = 4;
  s--;
  d--;
  vector<bool> visited(n);
  //cout << dfs(s,d,visited) << endl;
  for(int i = 0 ; i < n ; i++){
    visited[i] = 0;
  }
  vector<int> layers(n,-1);
  bfs(s,visited,layers);
  //print_layer(layers);
  for(int i = 0 ; i < n ; i++){
    visited[i] = 0;
  }
  vector<int> groups(n,0);
  bool isbipa = true;
  for(int i = 0 ; i < n ; i++){
    if(visited[i] == 0){
      if(!isbipartite(i,visited,groups)){
        isbipa = false;
        break;
      }
    }
  }
  //cout << isbipa << endl;
  
}

/*
5 3
1 2
2 3
3 4

*/
