/*
My solution
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, ans = 0;
        while (i < j) {
            int tmp = min(height[i], height[j]) * (j - i);
            if (tmp > ans) {
                ans = tmp;
            }
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> height{1,8,6,2,5,4,8,3,7};
    Solution solution;
    int ans = solution.maxArea(height);
    cout << "Max aera: " << ans;
}