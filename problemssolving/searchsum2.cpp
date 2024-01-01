#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
  vector<int> v;
  int n,k;
  map<int,int> m;
  cin >> n >> k;
  for(int i = 0 ; i < n ; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  for(int i = 0 ; i < n ; i++){
    int total_sum = 0;
    int min_sum = 0;
    // cout << "Finding for length : " << i+1 << endl;
    for(int j = 0 ; j < i+1 ; j++){
      // cout << "Sum at : " << j << endl;
      total_sum += v[j];
    }
    int pos_left = 0;
    int pos_right = i;
    while(pos_right != n){
      if(min_sum == 0 ){
        min_sum = total_sum;
      }else if(total_sum < min_sum){
        min_sum = total_sum;
      }
      total_sum+=v[pos_right+1];
      total_sum-=v[pos_left];
      pos_left++;
      pos_right++;
    }
    m[min_sum] = i+1;
  }
  for(auto i = m.begin() ; i != m.end() ; i++){
    // cout << "Length : " << i->first << " have : " << i->second << endl;
  }
  for(int i = 0 ; i < k ; i++){
    int a,result;
    cin >> a;
    auto it = m.lower_bound(a);
    if(it == m.end()){
      result = n;
    }else if(it->first == a){
      result = it->second;
    }else if(it != m.begin()){
      --it;
      result = it->second;
    }else{
      result = 0;
    }
    cout << result << endl;
  }
  
}

/*
4 4
17
10
20
30
50
30
29
7

*/