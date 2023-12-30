/*
Easy
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            auto diff = prices[i + 1] - prices[i];
            profit += max(diff, 0);
        }
        return profit;
    }
};