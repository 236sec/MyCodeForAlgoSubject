class Solution {
public:
    int jump(vector<int>& nums) {
        int s = 0;
        int e = nums[0];
        int choose = 1;
        int size = nums.size();
        if (size == 1) {
            return 0;
        }
        while (e < size - 1) {
            int max_jump = 0;
            for (int i = s; i <= e; i++) {
                if (i + nums[i] > max_jump) {
                    max_jump = i + nums[i];
                }
                s=i;
            }
            e = max_jump;
            choose++;
        }
        return choose;
    }
};
