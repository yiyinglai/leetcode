/*
Detail of the coin change does not matter, only the number of coins
State: fewest number of coins that make up some amount (infinite number of each kind of coin)

coinChange([1, 2], 10) = 5
coinChange([1, 2], 11) = min(coinChange([1], 11), coinChange([1, 2], 10) + 1, coinChange([1, 2], 9) + 1)
                       = min(11, 5 + 1, 5 + 1)
                       = 6

coinChange([1, 2, 5], 10) = 2
coinChange([1, 2, 5], 11) = min(coinChange([1, 2], 11), coinChange([1, 2, 5], 10) + 1, coinChange([1, 2, 5], 9) + 1, coinChange([1, 2, 5], 6) + 1)
                          = min(6, 2 + 1, 3 + 1, 2 + 1)
                          = 3

I had the basic idea wrong from above, it should be iterating over ranges of coins and there are only two cases: using new coin and not using new coin.
coinChange([all coins up to coins[i], j]) = min(coinChange([all coins up to coins[i - 1]], j - coins[i]) + 1, coinChange([all coins up to coins[i - 1]], j))

The ultimate problem is finding fewest number of coins, so the lower the values in a state the better.
At first my intuition was correct, using INT_MAX as initial values. But the problems was that in the state transition function, adding one to
INT_MAX causes numeric issue.

Using -1 as initial values makes it extremely messy and I couldn't even find out what went wrong for the following test case
[186,419,83,408]
6249 
*/

#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> f(amount + 1, -1);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] == j) {
                    f[j] = 1;
                    continue;
                }
                vector<int> fjs;
                for (int k = 0; k <= i && coins[k] <= j && f[j - coins[k]] >= 0; k++) {
                    if (f[j] == -1) {
                        fjs.push_back(f[j - coins[k]] + 1);
                    }
                    else
                        fjs.push_back(min(f[j], f[j - coins[k]] + 1));
                }
                if (!fjs.empty())
                    f[j] = *min_element(fjs.begin(), fjs.end());
            }
        }
        return f[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> f(amount + 1, amount + 1);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] <= j) {
                    f[j] = min(f[j], f[j - coins[i]] + 1);
                }
            }
        }
        if (f[amount] > amount)
            return -1;
        return f[amount];
    }
};