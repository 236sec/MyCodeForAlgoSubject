#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int calc_xsum(const unordered_map<int, int>& cnt, int x) {
        vector<pair<int, int>> freq;
        freq.reserve(cnt.size());
        for (const auto& [val, c] : cnt) {
            freq.emplace_back(c, val);
        }
        sort(freq.begin(), freq.end(), greater<pair<int, int>>());

        long long xsum = 0;
        for (int i = 0; i < x && i < freq.size(); ++i) {
            xsum += freq[i].first * freq[i].second;
        }
        return xsum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        // init map
        unordered_map<int, int> cnt;
        for (int i = 0; i < k; i++) {
            ++cnt[nums[i]];
        }
        ans.push_back(calc_xsum(cnt, x));

        // calculate
        for (int i = 1; i <= nums.size() - k; ++i) {
            // add right
            int rightVal = nums[i + k - 1];
            ++cnt[rightVal];

            // remove left
            int leftVal = nums[i - 1];
            if (--cnt[leftVal] == 0)
                cnt.erase(leftVal);

            ans.push_back(calc_xsum(cnt,x));
        }
        return ans;
    }
};