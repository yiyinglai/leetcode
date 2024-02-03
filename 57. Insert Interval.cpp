#include <vector>

using namespace std;

/*
Tired...
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (!intervals.size()) {
            return {newInterval};
        }

        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); ++i) {
            int tot_len = intervals[i][1] - intervals[i][0] + newInterval[1] - newInterval[0];
            int stride_sz = max(intervals[i][1], newInterval[1]) - min(intervals[i][0], newInterval[0]);
            // no overlap
            if (stride_sz > tot_len) {
                ans.push_back({intervals[i][0], intervals[i][1]});
            // overlap
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        if (!ans.size()) {
            ans.push_back({newInterval[0], newInterval[1]});
        } else {
            ans.push_back({newInterval[0], newInterval[1]});
            sort(ans.begin(), ans.end());
        }
        return ans;
    }
};