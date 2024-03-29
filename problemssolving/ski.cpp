#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int memo[100010];
struct Element {
    int h;
    int s;
};

int opt(int n,vector<Element> &v,int k){
    if(n>=v.size()){
        return 0;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    int result = v[n].s;
    for(int i = n+1 ; i < v.size() ; i++){
        if(v[n].h - v[i].h <= k && v[n].h - v[i].h >= 0){
            result = max(result,v[n].s+opt(i,v,k));
        }
    }
    memo[n] = result;
    return result;
}


int main() {
    int n,k;
    cin >> n >> k;
    vector<Element> v(n);
    for(int i = 0 ; i < n ; i++){
        int x,y;
        cin >> x >> y;
        v[i] = {x,y};
    }
    memset(memo,-1,sizeof(memo));
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans = max(ans,opt(i,v,k));
    }
    cout << ans << endl;
}

/*
5 4
10 10
5 10
6 1
8 2
7 2
*/