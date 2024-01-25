#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t, t2s;
        for (int i = 0; i < s.size(); ++i) {
            if (!s2t.count(s[i]) && !t2s.count(t[i])) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
                continue;
            }
            if (s2t[s[i]] == t[i] && t2s[t[i]] == s[i]) {
                continue;
            }
            return false;
        }
        return true;
    }
};