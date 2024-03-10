class Solution {
public:
    int opt(int i,int money,vector<int> &coins,vector<vector<int>> &memo){
        if(money < 0){
            return 0;
        }
        if(i == coins.size()-1){
            if(money%coins[i] == 0){
                return 1;
            }else{
                return 0;
            }
        }
        if(memo[i][money] != -1){
            return memo[i][money];
        }
        int take = 0;
        if(money>=coins[i]){
            take = opt(i,money-coins[i],coins,memo);
        }
        int notake = opt(i+1,money,coins,memo);
        int result = take + notake;
        memo[i][money] = result;
        return result;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size()+2, vector<int> (amount+2, -1));
        return opt(0,amount,coins,memo);
    }
};
