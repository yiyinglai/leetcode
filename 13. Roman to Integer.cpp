#include <iostream>
#include <string>
#include <stack>

using namespace std;
#if 0
// first attempt, not neccessary to use stack
class Solution {
public:
    unordered_map<char, int> roman2int {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        int ans = 0;
        stack<char> holder;
        while (!s.empty()) {
            holder.push(s.back());
            s.pop_back();
            if (s.empty()) {
                ans += roman2int[holder.top()];
                holder.pop();
                return ans;
            }
            if (roman2int[s.back()] < roman2int[holder.top()]) {
                ans += roman2int[holder.top()] - roman2int[s.back()];
                s.pop_back();
                holder.pop();
                continue;
            }
            ans += roman2int[holder.top()];
            holder.pop();
        }
        return ans;
    }
};
#endif
// second attempt, less space used
class Solution {
public:
    unordered_map<char, int> roman2int {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (i == 0) {
                ans += roman2int[s[i]];
                continue;
            }
            if (roman2int[s[i - 1]] < roman2int[s[i]]) {
                ans += roman2int[s[i]] - roman2int[s[i - 1]];
                i--;
            } else {
                ans += roman2int[s[i]];
            }
        }
        return ans;
    }
};

int main() {
    vector<string> strings { "III", "LVIII", "XC", "MDCLXVI"};
    Solution solution;
    for (const auto &s : strings) {
        int ans = solution.romanToInt(s);
        cout << s << " to integer is: " << ans << endl;
    }
}