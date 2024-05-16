#include <string>
#include <iostream>
#include <string>
using namespace std;

std::string to_camel_case(std::string text) {
  string ans;
  bool iscap = false;
  int count = 0;
  for(int i = 0 ; i < text.length() ; i++){
    if(iscap && text[i] >= 'a' && text[i] <= 'z'){
      text[i]=toupper(text[i]);
    }
    iscap = false;
    if(text[i]=='_' || text[i]=='-'){
      iscap = true;
      continue;
    }
    ans.push_back(text[i]);
  }
  return ans;
}