#include <iostream>
#include <vector>
#include <list>
using namespace std;
#define MAX_N 100009

vector<list<int>> adj(MAX_N);
vector<int> visited(MAX_N, 0);
vector<int> groups(MAX_N, 0);

void print_layer(vector<int> layers){
  for(int i = 0; i < layers.size(); i++){
    cout << i << " : " << layers[i] << endl;
  }
}

void create_graph(int n, int k) {
  for (int i = 0; i < k; i++) {
    int n, m;
    cin >> n >> m;
    adj[n].push_back(m);
    adj[m].push_back(n);
  }
  return;
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

bool isbipartite(int s){
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

int main() {
  int round;
  cin >> round;
  for(int j = 0 ; j < round ; j++){
    int n, m;
    cin >> n >> m;
    create_graph(n, m);
    bool result = true;
    for(int i = 1 ; i < n+1 ; i++){
      if(visited[i] == 1){
        continue;
      }else{
        if(!isbipartite(i)){
          result = false;
        }
      }
    }
    if(result){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
    for(int i = 0 ; i < n+5 ; i++){
      visited[i] = 0;
    }
    for(int i = 0 ; i < n+5 ; i++){
      groups[i] = 0;
    }
    for(int i = 0 ; i < n+5 ; i++){
      adj[i].clear();
    }
  }
}

/*
5 3
1 2
2 3
3 4

*/