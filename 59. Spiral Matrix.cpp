#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), total_elem = m * n;
        int lmt_up = 0, lmt_down = m, lmt_left = 0, lmt_right = n, cnt = 0;
        int row = 0, col = 0;
        vector<int> ans;
        while (cnt < total_elem) {
            while (col < lmt_right) {
                ans.emplace_back(matrix[row][col++]);
                if (++cnt >= total_elem) {
                    return ans;
                }
            }
            --col;
            ++row;
            ++lmt_up;
            while (row < lmt_down) {
                ans.emplace_back(matrix[row++][col]);
                if (++cnt >= total_elem) {
                    return ans;
                }
            }
            --row;
            --col;
            --lmt_right;
            while (col >= lmt_left) {
                ans.emplace_back(matrix[row][col--]);
                if (++cnt >= total_elem) {
                    return ans;
                }
            }
            ++col;
            --row;
            --lmt_down;
            while (row >= lmt_up) {
                ans.emplace_back(matrix[row--][col]);
                if (++cnt >= total_elem) {
                    return ans;
                }
            }
            ++row;
            ++col;
            ++lmt_left;
        }
        return ans;
    }
};