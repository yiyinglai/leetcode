/*
Highest price  - lowest price to get maximum profit.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest_price = 1e9;
        int max_profit = 0;
        for (auto const& price : prices) {
            lowest_price = min(lowest_price, price);
            max_profit = max(max_profit, price - lowest_price);
        }
        return max_profit;
    }
};