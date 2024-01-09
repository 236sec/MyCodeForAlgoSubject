#include <iostream>
#include <vector>
#include <list>
using namespace std;

int bfs(vector<vector<int>> &v,vector<vector<int>> &visited,int a,int b,int x, int y){
  list<pair<int,int>> sta;
  sta.push_back(make_pair(a,b));
  int layer = 0;
  //int country = 0;
  while(!sta.empty()){
    int nnode = sta.size();
    for(int i = 0 ; i < nnode ; i++){
      int q = sta.front().first;
      int w = sta.front().second;
      sta.pop_front();
      if(q < 0 || w < 0 || q >= v[0].size() || w >= v.size()){
        continue;
      }
      if(!visited[q][w]){
        cout << q << " " << w << " ";
        sta.push_back(make_pair(q,w+1));
        sta.push_back(make_pair(q+1,w));
        sta.push_back(make_pair(q-1,w));
        sta.push_back(make_pair(q,w-1));
      }
      visited[q][w] = 1;
      if(q == x && w == y){
        return layer;
      }
    }
    layer++;
  }
  return -1;
}

int main(){
  int r,c,a,b,x,y;
  cin >> r >> c >> a >> b >> x >> y;
  vector<vector<int>> v(r,vector<int>(c,0));
  for(int i = 0 ; i < r ; i++){
    for(int j = 0 ; j < c ; j++){
      int tmp;
      cin >> tmp;
      v[i][j] = tmp;
    }
  }
  vector<vector<int>> visited(r,vector<int>(c,0));
  int ans =  bfs(v,visited,a-1,b-1,x-1,y-1);
  cout << endl;
  cout << ans;
}
