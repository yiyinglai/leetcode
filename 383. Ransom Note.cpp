#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int target[26], source[26];
        memset(target, 0, 26);
        memset(source, 0, 26);
        for (const auto &ch : ransomNote) {
            ++target[ch - 'a'];
        }
        for (const auto &ch : magazine) {
            ++source[ch - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (target[i] > source[i]) {
                return false;
            }
        }
        return true;
    }
};