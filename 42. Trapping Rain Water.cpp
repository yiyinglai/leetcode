/*
Official solution, easiest version..
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size(), height[0]);
        vector<int> right_max(height.size(), height.back());
        for (int i = 1; i < height.size(); i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        for (int i = height.size() - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};

int main() {
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution;
    int ans = solution.trap(height);
    cout << "Rain trapped: " << ans;
}