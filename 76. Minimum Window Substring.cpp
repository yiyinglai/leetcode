#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// Official solution
class Solution {
public:
    unordered_map<char, int> ori, cnt;

    bool validSubstring() {
        for (const auto &c : ori) {
            if (cnt[c.first] < c.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c : t) {
            ++ori[c];
        }
        int l = 0, r = 0;
        int length = INT_MAX;
        int ans_l = -1;
        while (r < int(s.size())) {
            if (ori.count(s[r++])) {
                ++cnt[s[r - 1]]; // at first, I wrote it as ++cnt[s[r]]; and couldn't figure out why, until I asked gpt
            }
            while (validSubstring()) {
                if (r - l < length) {
                    ans_l = l;
                    length = r - l;
                }
                if (ori.count(s[l])) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }
        return length == INT_MAX ? "" : s.substr(ans_l, length);
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution solution;
    string ans = solution.minWindow(s, t);
    cout << "ans is: " << ans;
}