/*
My solution.
*/

#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (!isalnum(s[i]) && i < j) {
                i++;
            }
            while (!isalnum(s[j]) && i < j) {
                j--;
            }
            if (i < j) {
                if (tolower(s[i]) != tolower(s[j])) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};
