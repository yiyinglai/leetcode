#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);
        while (getline(ss, word, ' ')) {
            words.emplace_back(word);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<string, char> wd2ch;
        unordered_map<char, string> ch2wd;
        for (int i = 0; i < pattern.size(); ++i) {
            if (wd2ch.count(words[i]) && wd2ch[words[i]] != pattern[i] ||
                ch2wd.count(pattern[i]) && ch2wd[pattern[i]] != words[i]) {
                    return false;
            }
            wd2ch[words[i]] = pattern[i];
            ch2wd[pattern[i]] = words[i];
        }
        return true;
    }
};