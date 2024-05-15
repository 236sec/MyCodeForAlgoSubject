#include <vector>
using namespace std;

int score(const std::vector<int>& dice) {
  vector<int> numcount(6);
  // counting number in dice
  for(int i = 0 ; i < 5 ; i++){
      numcount[dice[i]-1]++;
  }
  int score = 0;
  // create rule of game here
  vector<pair<int,int>> rule = {{1,3},{6,3},{5,3},{4,3},{3,3},{2,3},{1,1},{5,1}};
  vector<int> scoreplus = {1000,600,500,400,300,200,100,50};
  int i = 0;
  while(true){
    if(i==8){
      break;
    }
    if(numcount[rule[i].first-1] >= rule[i].second){
      score+=scoreplus[i];
      numcount[rule[i].first-1]-=rule[i].second;
    }else{
      i++;
    }
  }
  return score; // return answer
}