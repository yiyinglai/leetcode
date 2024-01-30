#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (!nums.size()) {
            return vector<string>();
        }

        int start = 0, end = 0;
        vector<string> ans;
        for (end = 0; end < nums.size(); ++end) {
            if (end == nums.size() - 1 || (end != nums.size() - 1 && nums[end + 1] != nums[end] + 1)) {
                if (start == end) {
                    ans.emplace_back(to_string(nums[end]));
                } else {
                    ans.emplace_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                }
                start = end + 1;
            }
        }
        return ans;
    }
};