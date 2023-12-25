/*
It works.
*/

#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k > nums.size()) {
            k = k % nums.size();
        }
        vector<int> shifted;
        shifted.resize(k);
        copy_n(nums.end() - k, k, shifted.begin());
        for (int i = 0; i < nums.size() - k; i++) {
            nums[nums.size() - 1 - i] = nums[nums.size() - 1 - i - k];
        }
        copy_n(shifted.begin(), k, nums.begin());
    }
};