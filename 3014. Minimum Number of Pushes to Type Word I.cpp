#include <string>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if (n <= 8) {
            return n;
        } else if (n <= 16) {
            return 2 * n - 8;
        } else if (n <= 24) {
            return 8 + 16 + 3 * (n - 16);
        } else {
            return 8 + 16 + 24 + 4 * (n - 24);
        }
    }
};