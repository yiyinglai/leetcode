/*
Straight forward, but hey, it works.
*/

#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        std::map<int, int> val_count;
        for (auto const& num : nums) {
            if (!val_count[num]) {
                val_count[num] = 1;
            } else {
                val_count[num]++;
            }
        }
        for (auto const& pair : val_count) {
            if (pair.second > std::floor(nums.size() / 2)) {
                res = pair.first;
                break;
            }
        }
        return res;
    }
};