#include <iostream>
#include <list>
#include <vector>
using namespace std;
vector<list<int>> adj(1010);

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

int bfs(vector<list<int>> &adj, int pos, vector<int> visited,list<int> sta) {
  int count = 0;
  while(!sta.empty()){
    int nnode = sta.size();
    // cout << "Layer at : " << count << endl;
    count++;
    for(int j = 0 ; j < nnode ; j++){
      int pos = sta.front();
      visited[pos] = 1;
      for(auto i = adj[pos].begin() ; i != adj[pos].end() ; i++){
        if(visited[*i] == 0){
          visited[*i] = 1;
          // cout << "Visit : " << *i << endl;
          sta.push_back(*i);
        }
        if(*i == 1){
          return count;
        }
      }
      sta.pop_front();
    }
  }
  return -1;
}
int main() {
  int n, r;
  cin >> n >> r;
  vector<pair<int, int>> v;
  v.push_back(make_pair(0, 0));
  v.push_back(make_pair(100, 100));
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  if (r * r >= 10000) {
    cout << 1 << endl;
  } else {
    for (int i = 0; i < n+2; i++) {
      int a = v[i].first;
      int b = v[i].second;
      for (int j = i; j < n+2; j++) {
        if (j != i) {
          int c = v[j].first;
          int d = v[j].second;
          // cout << (c - a) * (c - a) + (d - b) * (d - b) << " " << r * r << endl;
          if ((c - a) * (c - a) + (d - b) * (d - b) <= r * r) {
            adj[i].push_back(j);
            adj[j].push_back(i);
          }
        }
      }
    }
    list<int> sta = {0};
    cout << bfs(adj, 0, vector<int>(n + 2, 0), sta) << endl;
    // for (int i = 0; i < 1000; i++) {
    //   if (!adj[i].empty()) {
    //     cout << "Graph " << v[i].first << " " << v[i].second << " : ";
    //     for (auto j = adj[i].begin(); j != adj[i].end(); j++) {
    //       cout << v[*j].first << " " << v[*j].second << " ";
    //     }
    //     cout << endl;
    //   }
    // }
  }
}