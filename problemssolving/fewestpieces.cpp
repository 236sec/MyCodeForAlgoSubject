#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int>> v(m,vector<int>(n));
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            int x;
            cin >> x;
            v[i][j] = x;
        }
    }
    vector<vector<int>> ans(m,vector<int>(n));
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            int prize = 1000000;
            //1
            int sum = 0;
            for(int k = 0 ; k <= j ; k++){
                sum+= v[i][k];
            }
            prize = min(prize,sum);
            //2
            sum = 0;
            for(int k = 0 ; k <= i ; k++){
                sum+= v[k][j];
            }
            prize = min(prize,sum);
            //3
            sum = 0;
            for(int k = i ; k < m ; k++){
                sum+= v[k][j];
            }
            prize = min(prize,sum);
            //4
            sum = 0;
            for(int k = j ; k < n ; k++){
                sum+= v[i][k];
            }
            prize = min(prize,sum);
            ans[i][j] = prize;
        }
    }
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

/*
4 5
1 15 8 9 12
20 3 2 1 2
4 5 1 2 6
10 4 15 2 3
*/











/*
4 5
1 15 8 9 12
20 3 2 1 2
4 5 1 2 6
10 4 15 2 3

*/