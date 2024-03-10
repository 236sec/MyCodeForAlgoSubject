class Solution {
public:
    int memo[10001];

    int opt(int money,vector<int> &coins){
        if(money == 0){
            return 0;
        }
        if(money < 0){
            return -1;
        }
        if(memo[money] != -1){
            return memo[money];
        }
        int result = 200000;
        for(int i = 0 ; i < coins.size() ; i++){
            int tmp = opt(money-coins[i],coins);
            if(tmp == -1){
                continue;
            }
            result = min(tmp+1,result);
        }
        memo[money] = result;
        return result;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(memo, -1, sizeof(memo));
        int ans = opt(amount,coins);
        if(ans == 200000){
            ans = -1;
        }
        return ans;
    }
};
