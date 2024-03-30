#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
string s;
int memo[210][210];

bool ismatch(char a,char b){
    if(a == 'A' && b == 'U'){
        return true;
    }else if(a == 'U' && b == 'A'){
        return true;
    }else if(a == 'G' && b == 'C'){
        return true;
    }else if(a == 'C' && b == 'G'){
        return true;
    }
    return false;
}

int opt(int i, int j){
    if(j-i<=4){
        return 0;
    }
    if(i >= j){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int result = opt(i,j-1);
    for(int k = i ; k < j-4 ; k++){
        if(ismatch(s[k],s[j])){
            result = max(result,1+opt(i,k-1)+opt(k+1,j-1));
        }
    }
    memo[i][j] = result;
    return result;
}

int main() {
  cin >> s;
  memset(memo, -1, sizeof(memo));
  cout << opt(0,s.length()-1) << endl;
//   for(int i = 0 ; i < s.size() ; i++){
//     for(int j = 0 ; j < s.size() ; j++){
//         cout << memo[i][j] << " ";
//     }
//     cout << endl;
//   }
}

/*
GCGAUGCGCAUAACG

GCGAUGCGCAUAACGCGCAAAAAGCGU
*/