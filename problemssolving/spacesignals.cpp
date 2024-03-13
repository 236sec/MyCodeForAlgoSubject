#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
string s;
string t;
int memo[200010][21];


int opt(int i,int k){
    if(i>=t.size()){
        return 0;
    }
    if(memo[i][k] != -1){
        return memo[i][k];
    }
    int found = 0;
    if(t[i] == s[k]){
        k+=1;
        found = 1;
        if(k == s.size()){
            k = 0;
        }
    }
    int result = opt(i+1,k)+found;
    memo[i][k] = result;
    return result;
}

int main() {
    cin >> s;
    cin >> t;
    memset(memo,-1,sizeof(memo));
    cout << opt(0,0)/s.size() << endl;
}



/*
HELLO
GOODHEBYELLOHELLBOYWHYDONTHELOVEMELIKEYOUIDSAYHELLO

*/