#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int memo[201][201][201];


int opt(int i, int j, int k, int limitk, vector<vector<int>> &v){
    if(k>limitk){
        return 0;
    }
    if(i == v.size()){
        return 0;
    }
    if(j<0 || j==v[0].size()){
        return 0;
    }
    if(memo[i][j][k] != -1){
        return memo[i][j][k];
    }
    int result = max({opt(i+1,j,k,limitk,v),opt(i+1,j-1,k+1,limitk,v),opt(i+1,j+1,k+1,limitk,v)}) + v[i][j];
    memo[i][j][k] = result;
    return result;
}

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int x;
            cin >> x;
            v[i][j] = x;
        }
    }
    memset(memo,-1,sizeof(memo));
    int ans = 0;
    for(int j = 0 ; j < m ; j++){
        ans = max(ans,opt(0,j,0,k,v));
    }
    cout << ans << endl;
}


/*
4 5 0
3 6 7 3 1
7 100 3 2 5
10 2 1 1 6
20 3 1 50 3
*/