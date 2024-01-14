#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; i++) {
            if (ratings[i + 1] > ratings[i] && candy[i + 1] <= candy[i]) {
                candy[i + 1] = candy[i] + 1;
            }
        }
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i] && candy[i - 1] <= candy[i]) {
                candy[i - 1] = candy[i] + 1;
            }
        }
        return accumulate(candy.cbegin(), candy.cend(), 0);
    }
};