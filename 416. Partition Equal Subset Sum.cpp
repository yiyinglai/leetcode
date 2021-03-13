/*
# Dynamic Programming
# 0-1 knapsack

Ultimate question: 
State: whether of not fit in a knapsack of volume j with part of the items[0, ..., i]

If at some point, items[0, ..., i] can fit in a knapsack of volumn sum / 2, the algorithm can stop.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2) return false;

        const int n = nums.size();
        const int half = sum / 2;
        vector<vector<int> > dp(n, vector<int>(half + 1, 0));
        if (nums[0] <= half) {
            dp[1][nums[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < half + 1; j++) {
                // item i does nothing from dp[i - 1][j] to dp[i][j], because no space is available for item i
                dp[i][j] = dp[i - 1][j];

                // Item i alone fits the knapsack
                if (nums[i] == j) dp[i][j] = 1;
                // Previous items fit the knapsack or item i and previous items together fit the knapsack
                else if (j > nums[i]) {
                    if (dp[i - 1][j] || dp[i - 1][j - nums[i]])
                    dp[i][j] = 1;
                }
            }
            if (dp[i][half] == 1) return true;
        }
        return dp[n - 1][half] == 1;
    }
};

// Optimized less space
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2) return false;

        const int n = nums.size();
        const int half = sum / 2;
        vector<int> dp(half + 1, 0);
        if (nums[0] <= half) {
            dp[nums[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = half; j >= 1; j--) {
                // Item i alone fits the knapsack
                if (nums[i] == j) dp[j] = 1;
                // Previous items fit the knapsack or item i and previous items together fit the knapsack
                else if (j > nums[i]) {
                    if (dp[j] || dp[j - nums[i]])
                    dp[j] = 1;
                }
            }
            if (dp[half] == 1) return true;
        }
        return dp[half] == 1;
    }
};

int main () {
    Solution solu;
    vector<int> nums = { 1, 2, 5 };
    cout << (int)solu.canPartition(nums) << endl;
    if (solu.canPartition(nums)) cout << "true" << endl;
    else cout << "false" << endl;
}