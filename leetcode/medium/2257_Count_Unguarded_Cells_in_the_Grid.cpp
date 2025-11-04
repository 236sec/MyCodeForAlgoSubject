struct PairHash {
    size_t operator()(const pair<int, int>& p) const noexcept {
        return hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};

class Solution {
public:
        int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0 ; i < walls.size() ; i++) {
            visited[walls[i][0]][walls[i][1]] = 3;
        }
        for (int i = 0 ; i < guards.size() ; i++) {
            visited[guards[i][0]][guards[i][1]] = 2;
        }

        for (int i = 0 ; i < guards.size() ; i++) {
            int x = guards[i][0];
            int y = guards[i][1];
            // Up
            for (int j = x - 1 ; j >= 0 ; j--) {
                if (visited[j][y] == 2 || visited[j][y] == 3) break;
                visited[j][y] = 1;
            }
            // Down
            for (int j = x + 1 ; j < m ; j++) {
                if (visited[j][y] == 2 || visited[j][y] == 3) break;
                visited[j][y] = 1;
            }
            // Left
            for (int j = y - 1 ; j >= 0 ; j--) {
                if (visited[x][j] == 2 || visited[x][j] == 3) break;
                visited[x][j] = 1;
            }
            // Right
            for (int j = y + 1 ; j < n ; j++) {
                if (visited[x][j] == 2 || visited[x][j] == 3) break;
                visited[x][j] = 1;
            }
        }
        int count = 0;
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (visited[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};
