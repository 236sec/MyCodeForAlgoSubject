class Solution {
public:
    int memo[46];
    int climbStairs(int n) {
        memset(memo,-1,sizeof(memo));
        memo[0] = 1;
        memo[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            memo[i] = memo[i-2] + memo[i-1]; 
        }
        return memo[n];
    }
};