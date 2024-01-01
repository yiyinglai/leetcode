/*
Simulate the process.
Jump to the furthest position each time.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int prev = 0, max = 0, n = nums.size(), jump = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i <= prev) {
                max = std::max(max, i + nums[i]);
                if (i == prev) {
                    jump++;
                    prev = max;
                }
            }
        }
        return jump;
    }
};