class Solution {
public:
    int memo[30010][2];
    int opt(int n,int k,vector<int> &v) {
        if(n==v.size()-1){
            if(k==1){
                return v[n];
            }
            return 0;
        }
        if(memo[n][k] != -1){
            return memo[n][k];
        }
        int result;
        if(k==1){
            result = max(opt(n+1,1,v),opt(n+1,0,v)+v[n]);
        }
        if(k==0){
            result = max(opt(n+1,0,v),opt(n+1,1,v)-v[n]);
        }
        memo[n][k] = result;
        return result;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(memo,-1,sizeof(memo));
        return opt(0,0,prices);
    }
};