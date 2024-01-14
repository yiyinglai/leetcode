#include <iostream>
#include <vector>

using namespace std;

#if 0
// first attempt, timed out
class Solution {
public:
    bool checkStartFromI(vector<int>& gas, vector<int>& cost, int i) {
        int n = gas.size();
        int tank = 0;
        for (int j = 0; j < n; j++) {
            int cur = i % n;
            if (cost[cur] > tank + gas[cur]) {
                return false;
            }
            tank += gas[cur] - cost[cur];
            i++;
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ret = -1;
        for (int i = 0; i < n; i++) {
            if (checkStartFromI(gas, cost, i)) {
                ret = i;
                break;
            }
        }
        return ret;
    }
};
#else
// improve
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = -1;
        int i = 0;
        while (i < n) {
            int j = 0, tank = 0;
            while (j < n) {
                tank += gas[(i + j) % n] - cost[(i + j) % n];
                if (tank < 0) {
                    i = i + j + 1;
                    break;
                }
                j++;
            }
            if (j == n) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
#endif

int main() {
    vector<int> gas{1,2,3,4,5};
    vector<int> cost{3,4,5,1,2};
    Solution solution;
    int ret = solution.canCompleteCircuit(gas, cost);
    cout << "starting index: " << ret;
}