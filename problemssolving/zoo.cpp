#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main() {
    int r,c,water,eat;
    cin >> r >> c >> water >> eat;
    vector<int> v(r);
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            int x;
            cin >> x;
            v[i] += x;
        }
    }
    int count = 0;
    float bird = floor((float)water/(float)eat);
    for(int i = 0 ; i < r ; i++){
        if(v[i] == 0){
            continue;
        }
        int result = ceil((float)v[i]/bird);
        //cout << v[i] << bird << " ";
        //cout << result << endl;
        count+=result;
    }
    cout << count << endl;
}


/*
3 4 11 4
10 5 1 1
3 4 0 0
0 0 0 0
*/