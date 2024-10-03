class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = -101;
        vector<int> ans;
        int numcount = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != last){
                ans.push_back(nums[i]);
                numcount++;
            }
            last = nums[i];
        }
        nums = ans;
        return numcount;
    }
};