#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#define INT_MAX 2147483647
using namespace std;
int memo[5002][5002];


int opt(int n,int k,vector<int> &v,int default_k){
    if(n >= v.size() && k>=0){
        return 0;
    }
    if(memo[n][k] != -1){
        return memo[n][k];
    }
    int result = INT_MAX;
    if(k >= v[n]){
        result = min(result,opt(n+1,k-v[n],v,default_k));
    }
    result = min(result,opt(n+1,default_k,v,default_k)+v[n]);
    memo[n][k] = result;
    return result;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n+1);
    v[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> v[i];
    }
    memset(memo,-1,sizeof(memo));
    cout << opt(1,k,v,k) << endl;
    /*
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= k ; j++){
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
    */
}

/*
8 10
1 2 3 4 5 1 2 3
*/
