/*
*/

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> num_index;
        for (int i = 0; i < nums.size(); i++) {
            if (num_index.count(nums[i])) {
                return {num_index[nums[i]], i};
            }
            num_index[target - nums[i]] = i;
        }
        return {-1, -1};
    }
};