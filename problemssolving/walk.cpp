#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n, z, d, e;
  cin >> n >> z >> d >> e;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = x;
  }
  int car = 0;
  int fuel = d;
  int selected = -1;
  int count = 0;
  for(int i = 0 ; i < n ; i++){
    //cout << "Car at "<< car << endl;
    if(car+fuel+e >= z){
      break;
    }
    if(v[i] <= car+fuel){
      selected = i;
    }else if(v[i] > car+fuel){
      if(v[i] <= car+fuel+e){
        //cout << "Walk to  "<< v[i] << endl;
        car += d;
        count++;
      }else if(selected != -1){
        //cout << "Stop at  "<< v[selected] << endl;
        car = v[selected];
        count++;
        i--;
      }else{
        count = -1;
        break;
      }
      selected = -1;
    }
  }
  if(selected != -1 && car < z){
    car = v[selected];
    count++;
  }
  cout << count;
}

/*
3 100 48 15
10 45 60

3 100 50 2
10 45 60

3 100 20 80
10 45 60

3 100 20 5
10 45 60

3 100 50 0
10 45 60

*/