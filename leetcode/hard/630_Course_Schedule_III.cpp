class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> q;
        pair<int,int> cou[courses.size()];
        for(int i = 0 ; i < courses.size() ; i++){
            cou[i].second = courses[i][0];
            cou[i].first = courses[i][1];
        }
        sort(cou,cou+courses.size());
        int dayat = 0;
        int count = 0;
        for(int i = 0 ; i < courses.size() ; i++){
            cout << cou[i].first << " " << dayat+cou[i].second<< endl;
            if(cou[i].first >= dayat+cou[i].second){
                q.push(cou[i].second);
                dayat += cou[i].second;
                count++;
            }else{
                if(q.empty()){
                  continue;
                }
                int max_du = q.top();
                if(max_du > cou[i].second){
                    q.pop();
                    dayat-=max_du;
                    dayat+=cou[i].second;
                    q.push(cou[i].second);
                }
            }
        }
        return count;
    }
};
