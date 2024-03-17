#include <iostream>
#include <vector>
#include <list>
using namespace std;

void bfs(vector<list<int>> &adj, int pos ,vector<bool> &visited,int layer) {
  if(visited[pos] == 1){
    return;
  }
  visited[pos] = 1;
  //cout << pos << " Layer : " << layer << endl;
  layer++;
  for(auto i = adj[pos].begin(); i != adj[pos].end(); i++) {
    bfs(adj,*i , visited,layer);
  }
}
int main() {
    int n;
    cin >> n;
    vector<list<int>> adj(n);
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        adj[i].push_back(x-1);
    }
    vector<bool> visited(n);
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        if(visited[i] != 1){
            bfs(adj,i,visited,0);
            count++;
        }
    }
    cout << count << endl;
}

/*
8
2 4 6 8 1 3 5 7

*/