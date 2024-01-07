#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<bool>> &visited, vector<bool> &isfind,
         vector<vector<char>> mat,int &count) {
  if (x < 0 || y < 0 || x >= mat.size() || y >= mat[0].size() ||
      visited[x][y] == true) {
    return;
  }
  if(mat[x][y] == '#'){
    return;
  }
  // if (isfind[0] == true && isfind[1] == true) {
  //   return;
  // }
  count++;
  visited[x][y] = 1;
  if (mat[x][y] == '$') {
    // cout << "Found element";
    isfind[1] = true;
  }
  if (mat[x][y] == '*') {
    // cout << "Found forest";
    isfind[0] = true;
  }
  // cout << "Go next " << endl;
  dfs(x + 1, y, visited, isfind, mat,count);
  dfs(x, y + 1, visited, isfind, mat,count);
  dfs(x - 1, y, visited, isfind, mat,count);
  dfs(x, y - 1, visited, isfind, mat,count);
  return;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> mat(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }
  int good_count = 0;
  int count = 0;
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // cout << "Checking at " << i << " " << j << " = " << mat[i][j] << endl;
      if (mat[i][j] == '.' || mat[i][j] == '$' || mat[i][j] == '*') {
        vector<bool> isfind;
        int counting = 0;
        // keep [ findforest , findelement   ]
        isfind.push_back(0);
        isfind.push_back(0);
        dfs(i, j, visited, isfind, mat,counting);
        // cout << isfind[0] << " " << isfind[1] << endl;
        if(isfind[0] && isfind[1]){
          good_count+= counting;
        }else if(isfind[0] || isfind[1]){
          count+= counting;
        }
      }
    }
    // cout << endl;
  }
  cout << good_count << " " << count ;
}
/*
7 8
.*..#...
....#...
.$.#..*#
..#..##.
.#.##...
#....###
..$.....

*/
