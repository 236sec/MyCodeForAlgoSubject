#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
k = 1 right
k = 2 left
k = 3 up
k = 4 down
*/
int travel(int i,int j,int k,vector<vector<int>> &v){
    if(v[i][j] == -1){
        if(k == 1){
            return travel(i,j+1,k,v);
        }
        else if(k == 2){
            return travel(i,j-1,k,v);
        }
        else if(k == 3){
            return travel(i-1,j,k,v);
        }
        else if(k == 4){
            return travel(i+1,j,k,v);
        }
    }else if(v[i][j] == -2){
        if(k == 1){
            return travel(i-1,j,3,v);
        }
        else if(k == 2){
            return travel(i+1,j,4,v);
        }
        else if(k == 3){
            return travel(i,j+1,1,v);
        }
        else if(k == 4){
            return travel(i,j-1,2,v);
        }
    }
    else if(v[i][j] == -3){
        if(k == 1){
            return travel(i+1,j,4,v);
        }
        else if(k == 2){
            return travel(i-1,j,3,v);
        }
        else if(k == 3){
            return travel(i,j-1,2,v);
        }
        else if(k == 4){
            return travel(i,j+1,1,v);
        }
    }
    return v[i][j];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n+2,vector<int> (n+2));
    int count = 1;
    for(int i = 1 ; i < n+1 ; i++){
        v[i][0] = count;
        count++;
    }
    for(int j = 1 ; j < n+1 ; j++){
        v[n+1][j] = count;
        count++;
    }
    for(int i = n ; i > 0 ; i--){
        v[i][n+1] = count;
        count++;
    }
    for(int j = n ; j > 0 ; j--){
        v[0][j] = count;
        count++;
    }
    for(int i = 1 ; i < n+1 ; i++){
        for(int j = 1 ; j < n+1 ; j++){
            char x;
            int num;
            cin >> x;
            if(x == '.'){
                num = -1;
            }
            if(x == '/'){
                num = -2;
            }
            if(x == '\\'){
                num = -3;
            }
            v[i][j] = num;
        }
    }
    // for(int i = 0 ; i < n+2 ; i++){
    //     for(int j = 0 ; j < n+2 ; j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i = 1 ; i < n+1 ; i++){
        cout << travel(i,1,1,v) << endl;
    }
    for(int j = 1 ; j < n+1 ; j++){
        cout << travel(n,j,3,v) << endl;
    }
    for(int i = n ; i > 0 ; i--){
        cout << travel(i,n,2,v) << endl;
    }
    for(int j = n ; j > 0 ; j--){
        cout << travel(1,j,4,v) << endl;
    }
}

/*
3
...
...
...

4
...\ 
.... 
.//. 
.\..
*/