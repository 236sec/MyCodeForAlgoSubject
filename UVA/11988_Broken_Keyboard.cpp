#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
  string st;
  while(getline(cin, st)) {
    list<string> l;
    string tmp;
    char lastseen = '[';
    for(auto i = st.begin() ; i != st.end() ; i++){
      if(*i == '['){
        if(lastseen == '['){
          l.push_front(tmp);
          tmp.clear();
        }if(lastseen == ']'){
          l.push_back(tmp);
          tmp.clear();
        }
        lastseen = '[';
      } else if (*i == ']') {
        if(lastseen == '['){
          l.push_front(tmp);
          tmp.clear();
        }if(lastseen == ']'){
          l.push_back(tmp);
          tmp.clear();
        }
        lastseen = ']';
      } else {
        tmp+=*i;
      }
    }
    if(!tmp.empty()){
      if(lastseen == '['){
        l.push_front(tmp);
        tmp.clear();
      }
      if(lastseen == ']'){
        l.push_back(tmp);
        tmp.clear();
      }
    }
    for(auto i = l.begin() ; i != l.end() ; i++){
      cout << *i;
    }
    cout << endl;
  }
}
