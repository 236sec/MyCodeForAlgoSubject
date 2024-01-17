#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
using namespace std;

void create_graph(int k,vector<list<int>> &adj,map<int,int> &indegree) {
  for (int i = 0; i < k; i++) {
    int n, m;
    cin >> n >> m;
    adj[n].push_back(m);
    indegree[m]++;
  }
}

void bfs(list<int> &sta,vector<int> &visited,map<int,int> &indegree,vector<list<int>> &adj) {
  int count = 0;
  // for(auto i = sta.begin() ; i != sta.end() ; i++){
  //   if(is_des(destination, *i)){
  //     destination[*i] = 0;
  //   }
  // }
  while(!sta.empty()){
    int nnode = sta.size();
    // cout << "Layer at : " << count << endl << "Have : ";
    // for(auto j = sta.begin() ; j != sta.end() ; j++){
    //   cout << *j << " ";
    // }
    // cout << endl;
    count++;
    for(int j = 0 ; j < nnode ; j++){
      int pos = sta.front();
      cout << pos << " ";
      visited[pos] = 1;
      for(auto i = adj[pos].begin() ; i != adj[pos].end() ; i++){
        indegree[*i]--;
        if(indegree[*i] == 0){
          sta.push_back(*i);
        }
      }
      sta.pop_front();
    }
  }
  cout << endl;
  return;
}

int main() {
  int n,m;
  list<int> stack_node;
  map<int,int> indegree;
  vector<list<int>> adj(150);
  while(cin >> n >> m){
    if(n==0 && m==0){
      break;
    }
    create_graph(m,adj,indegree);
    for(auto i = 1 ; i <= n ; i++) {
      if(indegree[i] == 0){
        stack_node.push_back(i);
      }
    }
    if(stack_node.empty()){
      cout << "no" << endl;
    }else{
      vector<int> visited(n+1,0);
      bfs(stack_node,visited,indegree,adj);
    }
    stack_node.clear();
    indegree.clear();
    for(int i = 0 ; i < n+1 ; i++){
      adj[i].clear();
    }
  }
}
