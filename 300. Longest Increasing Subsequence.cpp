/*
Ultimate problem: the length of longest increasing subsequence.
State: the lenght of longest increasing subsequence for all nums up to nums[i]
State transition function: for all states before nums[i], update states[i] if necessary.

Time complexity O(n ** 2)
Space complexity O(n)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> f(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    f[i] = max(f[i], f[j] + 1);
            }
        }
        return *max_element(f.begin(), f.end());
    }
};

/*
Only focus on the last element in an increasing subsequence, for subsequences with length 1, 2, 3...

For each new number nums[i], what we will do is either  1. append it to the end of dp if it extends the longest increasing subsequence
                                                        2. update an element of dp[j] if it makes the longest increasing subsequence with length j + 1 "better",
                                                           meaning dp[j] becomes smaller (updated to nums[i]), so the possibility of extending its length is higher.
                                                           Example IS [1, 2] and [1, 30] are both of length 2, and [1, 2] is better, because it is more possible
                                                           to be extended by an upcoming number, say 10, and becomes [1, 2, 10] while [1, 30] cannot be extened by 10.

The above index j for appending or replacing can be found by binary search on the dp array since the array will be sorted no matter what.
IS with length k ends with element dp[k - 1], and IS with length k + 1 ends with element dp[k].
dp[k - 1] is the smallest element at the back of all IS with length k, and IS with length k + 1 comes from IS with length k appended with a new element.
This new element must be greater than dp[k - 1]


len ->      1   2   3   4   5   6
min_back    10                          for nums in range [0->0], the smallest element at the back of all increasing subsequences with length 1 ([10]) is set to 10
            9                           for nums in range [0->1], the smallest element at the back of all increasing subsequences with length 1 ([10][9]) is updated to 9
            2                           for nums in range [0->2], the smallest element at the back of all increasing subsequences with length 1 ([10][9][2]) is updated to 2
            2   5                       for nums in range [0->3], the smallest element at the back of all increasing subsequences with length 2 ([*, 5]) is set to 5
            2   3                       for nums in range [0->4], the smallest element at the back of all increasing subsequences with length 2 ([*, 3]) is setated to 3
            2   3   7                   for nums in range [0->5], the smallest element at the back of all increasing subsequences with length 3 ([*, 7]) is set to 7
            2   3   7   101             for nums in range [0->6], the smallest element at the back of all increasing subsequences with length 4 ([*, 101]) isetet to 101
            2   3   7   101             for nums in range [0->6], the smallest element at the back of all increasing subsequences with length 4 ([*, 101 is seseto 87101
            2   3   7   8               for nums in range [0->7], the smallest element at the back of all increasing subsequences with length 4 ([*, 8]) is set to 8

Time complexity O(n * lgn)
Space complexity O(n)
*/
class Solution {
public:
    int indexOfInsertion(const vector<int>& vec, int x) {     
        int left = 0, right = vec.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (vec[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (left < vec.size() && right >= 0)
            return left;
        if (right < 0)
            return 0;
        return vec.size();
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(1, nums[0]);
        for (int i = 0; i < nums.size(); i++) {
            int idx = indexOfInsertion(dp, nums[i]);
            if (idx == dp.size())
                dp.push_back(nums[i]);
            else
                dp[idx] = nums[i];
        }
        return dp.size();
    }
};