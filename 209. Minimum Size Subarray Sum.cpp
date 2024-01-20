
#include <vector>
#include <iostream>

using namespace std;

//My solution, 1hr
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, i = 0, j = 0, sum = 0;
        do {
            if (sum < target) {
                sum += nums[j++];
            } else {
                int size = j - i;
                ans = min(ans, size);
                sum -= nums[i++];
            }
            if (j == nums.size() && sum < target) {
                break;
            }
        } while (true);
        return ans == INT_MAX ? 0 : ans;
    }
};

#if 0
// Official solution
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum >= s) {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
#endif

int main() {
    vector<int> nums{2,3,1,2,4,3};
    int target = 7;
    Solution solution;
    int ans = solution.minSubArrayLen(target, nums);
    cout << "ans: " << ans;
}