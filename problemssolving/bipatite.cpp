#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;

void create_graph(int n, int k,vector<list<int>> &adj) {
  for (int i = 0; i < k; i++) {
    int n, m;
    cin >> n >> m;
    adj[n].push_back(m);
    adj[m].push_back(n);
  }
  return;
}

void print_graph(int size,vector<list<int>> adj) {
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

bool is_visited(map<int, int> &m, int num) {
  if (m.find(num) != m.end()) {
    return true;
  }
  return false;
}

bool bfs(int start_pos, map<int, int> &destination,vector<list<int>> &adj) {
  int group = 0;
  list<int> sta;
  sta.push_back(start_pos);
  // cout << "Calling : " << start_pos << endl;
  destination[start_pos] = group;
  while (!sta.empty()) {
    int nnode = sta.size();
    // cout << "Layer at : " << count << endl << "Have : ";
    // for(auto j = sta.begin() ; j != sta.end() ; j++){
    //   cout << *j << " ";
    // }
    // cout << endl;
    for (int j = 0; j < nnode; j++) {
      int pos = sta.front();
      // cout << "Checking : " << pos << endl;
      for (auto i = adj[pos].begin(); i != adj[pos].end(); i++) {
        if (is_visited(destination, *i)) {
          if (destination[*i] == !group) {
            // cout << "Still Good" << endl;
            continue;
          } else {
            // cout << "Not Good : at " << *i << " " << destination[*i] << " != " << !group << endl;
            return false;
          }
        } else {
          destination[*i] = !group;
          // cout << *i << " : " << !group << endl;
          sta.push_back(*i);
        }
      }
      sta.pop_front();
    }
    group = !group;
  }
// for(auto i = sta.begin() ; i != sta.end() ; i++){
//   if(is_des(destination, *i)){
//     destination[*i] = 0;
//   }
// }
  return true;
}


int main() {
  int round;
  cin >> round;
  for(int j = 0 ; j < round ; j++){
    int n, m;
    cin >> n >> m;
    vector<list<int>> adj(100100);
    create_graph(n, m,adj);
    vector<int> visited(n + 2, 0);
    map<int, int> destination;
    bool result = true;
    for(int i = 1 ; i < n+1 ; i++){
      if(is_visited(destination, i)){
        continue;
      }else{
        if(!bfs(i,destination,adj)){
          result = false;
        }
      }
    }
    if(result){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }
}
