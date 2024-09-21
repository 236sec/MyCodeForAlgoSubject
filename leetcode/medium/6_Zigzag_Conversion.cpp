class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        } 
      int array_size = (s.size() / numRows) + 1;
        vector<vector<char>> arr(numRows);
        int row = 0;
        bool isup = 1;
        for(int i = 0 ; i < s.length() ; i++) {
            arr[row].push_back(s[i]); 
            if(row == numRows-1 && isup){
                isup = !isup;
            }
            if(row == 0 && !isup){
                isup = !isup;
            }
            if(isup){
                row+=1;
            }else{
                row-=1;
            }
        }
        string out;
        int length = 0;
        for(int i = 0 ; i < numRows ; i++){
            for(int j = 0 ; j < arr[i].size() ; j++){
                out+=arr[i][j];
            }
        }
        return out;  
    }
};