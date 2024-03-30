class Solution {
public:
    int memo[110][110];

    int opt(int i,int j,vector<vector<int>>& clips,int time){
        if(j>=time){
            return 0;
        }
        if(i>=clips.size()){
            return INT_MAX;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int result = opt(i+1,j,clips,time);
        if(clips[i][0] <= j){
            int tmp = opt(i+1,clips[i][1],clips,time);
            if(tmp == INT_MAX){
                memo[i][j] = min(result,tmp);
                return memo[i][j];
            }else{
                memo[i][j] = min(result,tmp+1);
                return memo[i][j];
            }
        }
        memo[i][j] = result;
        return result;
    }

    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        memset(memo,-1,sizeof(memo));
        int ans = opt(0,0,clips,time);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};