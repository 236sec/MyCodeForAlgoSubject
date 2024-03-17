#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

struct Element {
    int c;
    int b;
};

vector<Element> v(100010);
int memo[100010][4];

int opt(int i, int k){
    if(i<0){
        return 0;
    }
    if(memo[i][k] != -1){
        return memo[i][k];
    }
    int a1 = opt(i-1,0);
    int a2 = 0;
    if(k!=1){
        a2 = opt(i-1,1)+v[i].c;
    }
    int a3 = 0;
    if(k!=2){
        a3 = opt(i-1,2)+v[i].b;
    }
    int result = max({a1,a2,a3});
    memo[i][k] = result;
    return result;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x,y;
        cin >> x >> y;
        v[i] = {x,y};
    }
  memset(memo,-1,sizeof(memo));
    cout << opt(n-1,0) << endl;
}

/*
4
10 -5
4 -10
10 -1
35 -20
*/