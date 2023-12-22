/*
Similar to problem 26.
The key is that in a sequence, if nums[i] != nums[i-2],
the repeated elements is repeated twice at most.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = -1, size = nums.size();
        for (int j = 0; j < size; j++) {
            if ((j < 2) || (nums[i-1] != nums[j])) {
                nums[++i] = nums[j];
            }
        }
        return ++i;
    }
};