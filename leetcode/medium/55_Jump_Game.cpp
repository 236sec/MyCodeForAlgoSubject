class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            if(i > pos){
                return false;
            }
            int length = nums[i]+i;
            if(length > pos){
                pos = length;
            }
        }
        return true;
    }
};
