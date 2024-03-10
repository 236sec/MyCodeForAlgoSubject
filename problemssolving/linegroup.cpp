#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <limits>
#define MAX_N 1000000000
using namespace std;
map<pair<long long,long long>,long long> m;

long long opt(long long s,long long e,vector<long long> &v){
  if(s <= 0 || e <= 0){
    return 0;
  }
  if(s > e){
    return 0;
  }
  if(s==e){
    return MAX_N;
  }
  if(s>v.size()-1 || e>v.size()-1){
    return MAX_N;
  }
  if(m.find({s,e}) != m.end()){
    return m[{s,e}];
  }
  long long result = MAX_N;
  for(long long k = s+1 ; k < s+10 ; k++){
    long long max_value = 0;
    long long min_value = MAX_N;
    if(k>e){
      break;
    }
    for(long long i = s ; i <= k ; i++){
        //cout << v[i] << endl;
      min_value = min(min_value,v[i]);
      max_value = max(max_value,v[i]);
    }
    long long anoy = max_value - min_value;
    //cout << s << " " << k << endl;
    //cout << max_value << " - "<< min_value << " = " << anoy << endl;
    result = min(result,opt(k+1,e,v)+anoy);
  }
  m[{s,e}] = result;
  return result;
}


int main() {
  long long n;
  cin >> n;
  vector<long long> v(n+1);
  v[0] = 0;
  for(long long i = 1 ; i <= n ; i++){
    long long x;
    cin >> x;
    v[i] = x;
  }
  cout << opt(1,n,v) << endl;
}

/*

10
9 10 3 5 4 3 4 8 8 9

15
2 1 1 1 1 1 1 1 1 1 1 2 6 6 6


*/