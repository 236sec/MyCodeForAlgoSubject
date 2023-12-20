#include <iostream>
#include <list>
#include <vector>
using namespace std;
vector<list<int>> adj(110);

void create_graph(int k) {
  for (int i = 0; i < k; i++) {
    int n, m;
    cin >> n >> m;
    adj[n].push_back(m);
    adj[m].push_back(n);
  }
}

void print_graph(int size) {
  for (int i = 0; i < size; i++) {
    if (!adj[i].empty()) {
      cout << "Graph " << i << " : ";
      for (auto j = adj[i].begin(); j != adj[i].end(); j++) {
        cout << *j << " ";
      }
      cout << endl;
    }
  }
}

void bfs(vector<list<int>> &adj, int pos ,vector<int> visited,int layer) {
  if(visited[pos] == 1){
    return;
  }
  visited[pos] = 1;
  cout << pos << " Layer : " << layer << endl;
  layer++;
  for(auto i = adj[pos].begin(); i != adj[pos].end(); i++) {
    bfs(adj,*i , visited,layer);
  }
}
int main() {
  int k;
  cin >> k;
  create_graph(k);
  int pos = 0;
  for(int i = 0 ; i < 101 ; i++){
    if(!adj[i].empty()){
      pos = i;
      break;
    }
  }
  int layer = 0;
  bfs(adj, pos, vector<int>(110, 0),layer);
}
