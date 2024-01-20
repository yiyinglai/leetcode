#include <unordered_map>
#include <string>

using namespace std;

// My solution. Extremely slow, O(N2), repeating validating already validated elements.
#if 0
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, ans = 0;
        unordered_map<char, int> char_idx;
        while (i < s.size()) {
            int j = i;
            char_idx.clear();
            while (j < s.size() && !char_idx.count(s[j])) {
                char_idx[s[j]] = j;
                ++j;
            }
            ans = max(ans, (int)char_idx.size());
            if (j == s.size()) {
                return ans;
            }
            i = char_idx[s[j]] + 1;
        }
        return ans;
    }
};
#endif

// Elegant solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, ans = 0, length = 0, j = 0;
        unordered_map<char, int> char_idx;
        while (j < s.size()) {
            if (char_idx.count(s[j]) && char_idx[s[j]] >= i) {
                i = char_idx[s[j]] + 1;
                length = j - i;
            }
            char_idx[s[j]] = j;
            ++j;
            ++length;
            ans = max(ans, length);
        }
        return ans;
    }
};