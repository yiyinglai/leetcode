#include <vector>
#include <iostream>

using namespace std;

// My first solution, 10+ms. Time complexity O(NlogN)
#if 0
class Solution {
public:
    int findTarget(vector<int>& numbers, int left, int right, int target) {
        int mid = (left + right) / 2;
        if (left >= right) {
            return -1;
        }
        if (numbers[mid] == target) {
            return mid;
        } else if (numbers[mid] < target) {
            return findTarget(numbers, mid + 1, right, target);
        } else {
            return findTarget(numbers, left, mid, target);
        }
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, 0);
        for (int i = 0; i < numbers.size(); ++i) {
            int idx = findTarget(numbers, 0, numbers.size(), target - numbers[i]);
            if (idx == -1) {
                continue;
            }
            if (i != idx) {
                ans[0] = i + 1;
                ans[1] = idx + 1;
                break;
            } else if (idx != numbers.size() - 1 && numbers[idx + 1] == numbers[idx]) {
                ans[0] = i + 1;
                ans[1] = idx + 2;
                break;
            }
        }
        return ans;
    }
};
#endif
#if 0
// Improved, 4ms
class Solution {
public:
    int findTarget(vector<int>& numbers, int left, int right, int target) {
        int mid = (left + right) / 2;
        if (left >= right) {
            return -1;
        }
        if (numbers[mid] == target) {
            return mid;
        } else if (numbers[mid] < target) {
            return findTarget(numbers, mid + 1, right, target);
        } else {
            return findTarget(numbers, left, mid, target);
        }
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int idx = findTarget(numbers, i + 1, numbers.size(), target - numbers[i]);
            if (idx == -1) {
                continue;
            }
            return {i + 1, idx + 1};
        }
        return {-1, -1};
    }
};
#endif

// Time complexity O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> numbers{3,24,50,79,88,150,345};
    int target = 200;
    Solution solution;
    const auto ans = solution.twoSum(numbers, target);
    for (auto const& x : ans) {
        cout << x << " ";
    }
}