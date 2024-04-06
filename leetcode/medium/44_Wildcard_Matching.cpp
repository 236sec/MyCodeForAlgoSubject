class Solution {
public:
    int memo[2004][2004];
    int opt(int i , int j,string &s,string &p){
        if(i==s.size()){
            if(j==p.size()){
                return 1;
            }
            for(int k = j ; k < p.size() ; k++){
                if(p[k] != '*'){
                    return 0;
                }
            }
            return 1;
        }
        if(j==p.size()){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        bool result = 0;
        if(p[j] == '*'){
            result = (result || opt(i+1,j+1,s,p) || opt(i+1,j,s,p) || opt(i,j+1,s,p));
        }
        if(p[j] == s[i] || p[j] == '?'){
            result = (result || opt(i+1,j+1,s,p));
        }
        memo[i][j] = result;
        return result;
    }
    bool isMatch(string s, string p) {
        memset(memo,-1,sizeof(memo));
        int result = opt(0,0,s,p);
        if(result){
            return true;
        }else{
            return false;
        }
    }
};