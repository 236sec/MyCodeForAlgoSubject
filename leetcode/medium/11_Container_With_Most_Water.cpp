class Solution {
public:
    int maxArea(vector<int>& height) {
        int lid = 0;
        int rid = height.size() - 1;
        int max_con = 0;
        while(lid != rid){
            if(max_con < min(height[lid],height[rid])*(rid-lid)){
                max_con = min(height[lid],height[rid])*(rid-lid);
            }
            if(height[lid] > height[rid]){
                rid--;
            }else{
                lid++;
            }
        }
        return max_con;
    }
};
