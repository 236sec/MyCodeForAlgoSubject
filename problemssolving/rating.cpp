#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int memo[100010];

int opt(int i,vector<int> &v){
    if(i < 0){
        return 0;
    }
    if(memo[i] != -1){
        return memo[i];
    }
    int result = 1;
    for(int k = 1 ; k <= 6 ; k++){
        int tmp = opt(i-k,v);
        if(tmp!=0){
            if(v[i-k] == v[i]){
                result = opt(i-k,v)+1;
                break;
            }
        }
    }
    memo[i] = result;
    return result;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> v(m);
    for(int i = 0 ; i < m ; i++){
        cin >> v[i];
    }
    memset(memo,-1,sizeof(memo));
    int max_count = 0;
    int max_num = 0;
    for(int i = 0 ; i < m ; i++){
        int cal = opt(i,v);
        if(cal == max_count && max_num > v[i]){
            max_num = v[i];
        }else if(cal > max_count){
            max_num = v[i];
            max_count = cal;
        }
    }
    // for(int i = 0 ; i < m ; i++){
    //     cout << memo[i] << " ";
    // }
    // cout << endl;
    cout << max_num << " " << max_count << endl;
}

/*
9 19
1 1 3 2 3 3 4 4 5 2 4 3 6 7 8 9 1 2 3
*/