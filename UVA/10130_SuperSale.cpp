#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int memo[1010][32];
int prices[1010];
int weights[1010];
int carry[101];

int opt(int n,int w,int size) {
    if(n == size){
        return 0;
    }
    if(memo[n][w] != -1){
        return memo[n][w];
    }
    int result = opt(n+1,w,size);
    if(w>=weights[n]){
        result = max(result,opt(n+1,w-weights[n],size)+prices[n]);
    }
    memo[n][w] = result;
    return result;
}

void prin(int size){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < 32 ; j++){
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for(int r = 0 ; r < t ; r++){
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            int x,y;
            cin >> x >> y;
            prices[i] = x;
            weights[i] = y;
        }
        int g;
        cin >> g;
        for(int i = 0 ; i < g ; i++){
            int x;
            cin >> x;
            carry[i] = x;
        }
        int ans = 0;
        for(int i = 0 ; i < g ; i++){
            memset(memo,-1,sizeof(memo));
            //cout << "Send " << carry[i] << endl;
            ans += opt(0,carry[i],n);
            //prin(n);
        }
        cout << ans << endl;
    }
}

/*
1
3
72 17
44 23
31 24
1
26
*/