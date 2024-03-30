#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n,s;
    cin >> n >> s;
    vector<int> v(20);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    for(int i = 0 ; i < 20-n ; i++){
        v[n+i] = i+1;
    }
    vector<vector<int>> m(4,vector<int> (5));
    int count = 20-s;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            m[i][j] = v[count%20];
            count++;
        }
    }
    // for(int i = 0 ; i < 20 ; i++){
    //     cout << v[i] << " ";
    // }
    // for(int i = 0 ; i < 4 ; i++){
    //     for(int j = 0 ; j < 5 ; j++){
    //         cout << m[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "---------" << endl;
    for(int j = 0 ; j < 5 ; j++){
        for(int i = 0 ; i < 4 ; i++){
            cout << m[i][j] << " ";
        }
    }
}