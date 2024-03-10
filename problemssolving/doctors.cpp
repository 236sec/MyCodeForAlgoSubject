#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>
#define MAX_N 100010
using namespace std;

struct Element {
  int node;
  int weight;
};
vector<list<Element>> adj(MAX_N);
vector<int> dis(MAX_N, 10000);

void print_graph() {
  for (int i = 0; i < MAX_N; i++) {
    if (!adj[i].empty()) {
      cout << "Node " << i << endl;
      for (auto j = adj[i].begin(); j != adj[i].end(); j++) {
        cout << j->node << " " << j->weight << endl;
      }
    }
  }
}

int find_min(priority_queue<pair<int, int>> &q) { return q.top().second; }

void print_dis(int n) {
  for (int i = 0; i != n; i++) {
    cout << i + 1 << " : " << dis[i] << endl;
  }
}

void dijkstra(int start, int n) {
  priority_queue<pair<int, int>> q;
  dis[start] = 0;
  q.push({0, start});
  while (!q.empty()) {
    int min_node = find_min(q);
    q.pop();
    // cout << "We get : " << min_node+1 << endl;
    for (auto i = adj[min_node].begin(); i != adj[min_node].end(); i++) {
      if (dis[i->node] > dis[min_node] + i->weight) {
        dis[i->node] = dis[min_node] + i->weight;
        q.push({-dis[i->node], i->node});
      }
    }
    // print_dis(n);
  }
}

int main() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> people(n);
  for(int i = 0 ; i < n ; i++){
    int x;
    cin >> x;
    people[i] = x;
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  dijkstra(0, n);
  int total_cost = 0;
  for(int i = 1 ; i < n ; i++){
    if(people[i] <= l){
      total_cost += dis[i]*people[i];
    }else{
      total_cost += dis[i]*l;
    }
  }
  cout << total_cost << endl;
  // print_dis(n);
  
}
/*
4 5 4
0 1 2 7
1 2 5
3 1 14
2 3 7
4 2 11
1 4 15


*/