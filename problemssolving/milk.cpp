#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;
#define MAX_N 100010
vector<int> parent(MAX_N);
vector<int> groupam(MAX_N);

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
  for (int i = 0; i < m; i++) {
    char c;
    int u, v;
    cin >> c >> u >> v;
    u--;
    v--;
    if (c == 'c') {
      union_parent(u, v);
    }else if (c == 'q') {
      if (find(u) == find(v)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  }
}

/*
5 10
q 1 2
c 1 3
q 3 2
c 3 2
q 1 2
q 4 5
c 4 2
q 4 1
c 1 4
q 5 1

*/