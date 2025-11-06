class Solution {
public:
    void dfs(int id, int node, vector<list<int>>& adj, vector<int>& vis,
             vector<priority_queue<int, vector<int>, greater<int>>>& heaps,
             vector<int>& componentOf) {
        
        vis[node] = 1;
        heaps[id].push(node);
        componentOf[node] = id;

        for (int nxt : adj[node]) {
            if (!vis[nxt]) {
                dfs(id, nxt, adj, vis, heaps, componentOf);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {

        vector<list<int>> adj(c);

        for (auto& it : connections) {
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }

        vector<int> vis(c), online(c, 1);
        vector<priority_queue<int, vector<int>, greater<int>>> heaps(c);
        vector<int> componentOf(c);

        int id = 0;
        for (int i = 0; i < c; i++) {
            if (!vis[i]) {
                dfs(id, i, adj, vis, heaps, componentOf);
                id++;
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int type = q[0], node = q[1] - 1;
            int compId = componentOf[node];

            if (type == 2) {
                online[node] = 0;
                continue;
            }

            if (online[node]) {
                ans.push_back(node + 1);
            } else {
                while (!heaps[compId].empty() && !online[heaps[compId].top()]) {
                    heaps[compId].pop();
                }

                if (!heaps[compId].empty()) {
                    ans.push_back(heaps[compId].top() + 1);
                } else {
                    ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};
