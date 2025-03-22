using namespace std;
class Solution {
public:
    vector<list<int>> adj;
    vector<bool> visited;
    vector<int> groups;
    vector<int> layers;

    Solution() : adj(55), visited(55, 0), groups(55, 0), layers(55, -1) {}

    void create_graph(int n, int k) {
        adj[n].push_back(k);
        adj[k].push_back(n);
        return;
    }

    void bfs(int s,vector<bool> &visited,int &countedges,int &countnodes){
        list<int> sta;
        sta.push_back(s);
        countnodes++;
        while(!sta.empty()){
            int nnode = sta.size();
            for(int i = 0 ; i < nnode ; i++){
                int node = sta.front();
                visited[node] = true;
                for(auto j = adj[node].begin(); j != adj[node].end(); j++){
                    countedges++;
                    if(visited[*j] == false){
                        visited[*j] = 1;
                        sta.push_back(*j);
                        countnodes++;
                    }
                }
                sta.pop_front();
            }
        }
        return ;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            create_graph(u,v);
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++) {
            if(visited[i] == false) {
                int countedge = 0;
                int countnodes = 0;
                // cout << "Visited : " << i << endl;
                bfs(i,visited,countedge,countnodes);
                // cout << "Total Edge : " << countedge << endl;
                // cout << "Total Nodes : " << countnodes << endl;
                // cout << countnodes * (countnodes - 1) / 2 << " ==? " << countedge << endl;
                if(countnodes * (countnodes - 1) / 2 == countedge / 2) {
                    count++;
                };
            }
        }
        return count;
    }
};
