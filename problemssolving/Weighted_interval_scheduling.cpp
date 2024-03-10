#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int,int> m;

struct Element {
  int s;
  int f;
  int w;
};

int opt(int n , vector<Element> &v,vector<int> &p){
  if(m.find(n) != m.end()){
    return m[n];
  }
  int weight = v[n].w;
  int result = max(weight+opt(p[n],v,p),opt(n-1,v,p));
  m[n] = result;
  return result;
}

vector<int> cal_p(int n , vector<Element> &v){
  vector<int> p(n+1);
  p[0] = -1;
  for(int i = 1 ; i <= n ; i++){
    for(int j = i ; j >= 1 ; j--){
      if(v[i].s >= v[j].f){
        p[i] = j;
        break;
      }
    }
  }
  return p;
}

void print_sequnce(int n,int weight,vector<int> &p){
  int pos = n;
  while(m[pos] == weight){
    pos--;
  }
  pos++;
  int count = 0;
  vector<int> out;
  while(true){
    if(pos == 0){
      break;
    }
    out.push_back(pos);
    pos = p[pos];
    count++;
  }
  cout << count << endl;
  for(auto i = out.begin() ; i != out.end() ; i++){
    cout << *i << " ";
  }
  cout << endl;
  return;
}

int main() {
  int n;
  cin >> n;
  vector<Element> v(n+1);
  v[0] = {-1,-1,-1};
  for(int i = 1 ; i <= n ; i++){
    int s,f,w;
    cin >> s >> f >> w;
    v[i] = {s,f,w};
  }
  vector<int> p = cal_p(n,v);
  m[0] = 0;
  m[-1] = 0;
  int max_weight = opt(n,v,p);
  cout << max_weight << endl;
  print_sequnce(n,max_weight,p);
}

/*
3
1 3 2
2 4 3
3 5 2

3
1 3 2
2 4 10
3 5 2

6
1 4 2
2 6 4
5 7 4
3 10 7
8 11 2
9 12 1


Number of Jobs n = 4
 Job Details {Start Time, Finish Time, Profit}
 Job 1:  {1, 2, 50} 
 Job 2:  {3, 5, 20}
 Job 3:  {6, 19, 100}
 Job 4:  {2, 100, 200}
4
1 2 50
3 5 20
6 19 100
2 100 200
*/
