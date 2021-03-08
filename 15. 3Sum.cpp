/*
Using two for loops, and borrowing the idea of using hash table (unordered_map) from twoSum, the method has time complexity of O(n^2).
And the index j keeps starting from the beginning.

This solution also provides another approach to twoSum.
*/

#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> myset;
        for (int i = 0; i < nums.size(); i++) {
            // if (i > 0 && nums[i] == nums[i - 1]) continue;
            const int target = -nums[i];
            unordered_map<int, int> complement;
            for (int j = 0; j < nums.size() && j != i; j++) {
                // nums[i] = -1, target = 1, check if nums[j] was complement of previous nums[j]
                unordered_map<int, int>::iterator it = complement.find(nums[j]);
                if (it == complement.end()) {
                    complement.insert(unordered_map<int, int>::value_type(target - nums[j], j));
                }
                else {
                    vector<int> tmp;
                    // printf("nums[%d]: %d, nums[%d]: %d, nums[%d]: %d\n", i, nums[i], j, nums[j], it->second, nums[it->second]);
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[it->second]);
                    sort(tmp.begin(), tmp.end());
                    myset.insert(tmp);
                }
            }
        }
        vector<vector<int>> ans(myset.begin(), myset.end());
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        // for (auto num : nums) cout << num << " ";
        // cout << endl;
        for (int i = 0; i < nums.size(); i++) {
            // Skip repeating numbers
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // printf("i: %d\n", i);
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == -nums[i]) {
                    vector<int> v = { nums[i], nums[left], nums[right] };
                    ans.push_back(v);
                    // printf("i: %d, left: %d, right: %d\n", i, left, right);
                    // Move until value of left and right has changed
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                    continue;
                }
                if (nums[left] + nums[right] < -nums[i])
                    left++;
                if (nums[left] + nums[right] > -nums[i])
                    right--;
            }
        }
        return ans;
    }
};