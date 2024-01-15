#define MAX_N 2010
vector<list<int>> adj(MAX_N);
vector<int> indeg(MAX_N);
vector<bool> visited(MAX_N);

void print_graph(int numCourses) {
    for (int i = 0; i < numCourses; i++) {
        if (!adj[i].empty()) {
            cout << "Graph " << i << " : ";
            for (auto j = adj[i].begin(); j != adj[i].end(); j++) {
                cout << *j << " ";
            }
            cout << endl;
        }
    }
}

bool iscycle(list<int> &que,int numCourses){
    while(!que.empty()){
        int nnode = que.size();
        for(int i = 0 ; i < nnode ; i++){
            int pos = que.front();
            que.pop_front();
            for(auto j = adj[pos].begin() ; j != adj[pos].end() ; j++){
                indeg[*j]-=1;
                if(indeg[*j] == 0){
                    visited[*j] = 1;
                    que.push_back(*j);
                }
            }
        }
    }
    for(int i = 0 ; i < numCourses ; i++){
        if(visited[i] == 0){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto& prereq : prerequisites) {
            int course = prereq[1];
            int prerequisite = prereq[0];
            //cout << prerequisite << " " << course << endl;
            adj[prerequisite].push_back(course);
            indeg[course]+=1;
        }
        list<int> que;
        for (int i = 0; i < numCourses; i++) {
            if(indeg[i] == 0){
                que.push_back(i);
                visited[i] = 1;
            }
        }
        bool result = !iscycle(que,numCourses);
        for (int i = 0; i < numCourses; i++) {
            adj[i].clear();
            visited[i] = 0;
            indeg[i] = 0;
        }
        que.clear();
        if(result){
            return true;
        }else{
            return false;
        }
    }
};
