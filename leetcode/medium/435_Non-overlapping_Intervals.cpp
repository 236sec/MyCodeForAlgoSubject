class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        pair<int,int> inv[intervals.size()];
        for (int i = 0; i != intervals.size(); i++) {
            inv[i].first = intervals[i][1];
            inv[i].second = intervals[i][0];
        }
        sort(inv,inv+intervals.size());
        int max_late = -6*10000;
        int count = 0;
        for(int i = 0 ; i < intervals.size() ; i++){
            if(inv[i].second < max_late){
                count++;
                continue;
            }
            max_late = inv[i].first;
        }
        return count;
    }
};
