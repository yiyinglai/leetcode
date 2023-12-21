/*
From left to righ, move target values to the rightmost by swapping.
Yes, we might be swapping two target values, but that's okay. The
point is move the target values to the rightmost.

Why not think of it as swapping from both ends towards the middle?
Swapping involves two elements so we will have to consider parity (even or odd).
*/

#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (nums[i] == val) {
                nums[i] = nums[j--];
            } else {
                i++;
            }
        }
        return i;
    }
};