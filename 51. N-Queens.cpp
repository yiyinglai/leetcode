#include <iostream>
#include <vector>

using namespace std;

#if 0
// my own solution, 20 ms
class Solution {
public:
    vector<pair<int, int>> nextValidQueens(vector<pair<int, int>> queens, int n) {
        vector<pair<int, int>> ret;
        vector<bool> candidates(n, true);
        for (auto const& queen : queens) {
            candidates[queen.second] = false;
            int dist = queens.size() - queen.first;
            if (queen.second - dist >= 0) {
                candidates[queen.second - dist] = false;
            }
            if (queen.second + dist < n) {
                candidates[queen.second + dist] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (candidates[i]) {
                ret.emplace_back(queens.size(), i);
            }
        }
        return ret;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<pair<int, int>>> half_ans;
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            vector<pair<int, int>> seed_first_ans;
            seed_first_ans.emplace_back(0, i);
            half_ans.emplace_back(seed_first_ans);
        }
        while (!half_ans.empty()) {
            // generate next valid queen
            vector<pair<int, int>> next_valid_queens = nextValidQueens(half_ans.back(), n);
            if (next_valid_queens.empty()) {
                // got one answer
                if (half_ans.back().size() == n) {
                    auto const& half_ans_back = half_ans.back();
                    vector<string> tmp_ans;
                    for (auto const& queen : half_ans_back) {
                        string line(n, '.');
                        line[queen.second] = 'Q';
                        tmp_ans.emplace_back(line);
                    }
                    ans.emplace_back(tmp_ans);
                }
                half_ans.pop_back();
            } else {
                // there's still hope for a valid solution
                auto half_ans_back = half_ans.back();
                half_ans.pop_back();
                for (int i = 0; i < next_valid_queens.size(); i++) {
                    half_ans.emplace_back(half_ans_back);
                    half_ans.back().emplace_back(next_valid_queens[i]);
                }
            }
        }
        return ans;
    }
};
#endif
#if 0
// backtracking, 8 ms
class Solution {
public:
    static constexpr int max_size = 9;
    int board[max_size][max_size]; // 0 is empty, 1 is queen
    int board_size = 0;
    vector<vector<string>> ans;

    int getQueenCol(int board[max_size][max_size], int row) {
        int ret;
        for (int i = 0; i < board_size; i++) {
            if (board[row][i]) {
                ret = i;
                break;
            }
        }
        return ret;
    }

    void addAnswer(int board[max_size][max_size]) {
        vector<string> tmp_ans;
        for (int row = 0; row < board_size; row++) {
            string line(board_size, '.');
            int col = getQueenCol(board, row);
            line[col] = 'Q';
            tmp_ans.emplace_back(line);
        }
        ans.emplace_back(tmp_ans);
    }

    bool check(int board[max_size][max_size], int row, int col) {
        for (int i = 0; i < row; i++) {
            int j = getQueenCol(board, i);
            if (j == col) {
                return false;
            }
            if (std::abs(col - j) == std::abs(row - i)) {
                return false;
            }
        }
        return true;
    }

    void impl(int board[max_size][max_size], int row) {
        for (int col = 0; col < board_size; col++) {
            board[row][col] = 1;
            if (check(board, row, col)) {
                if (row == board_size - 1) {
                    addAnswer(board);
                    board[row][col] = 0;
                } else {
                    impl(board, row + 1);
                }
            } else {
                board[row][col] = 0;
                if (col == board_size - 1) {
                    int j = getQueenCol(board, row - 1);
                    board[row - 1][j] = 0;
                }
            }
            board[row][col] = 0;
        }
    }

    void print(int board[max_size][max_size]) {
        for (int i = 0; i < board_size; i++) {
            for (int j = 0; j < board_size; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board_size = n;
        for (int i = 0; i < max_size; i++) {
            for (int j = 0; j < max_size; j++) {
                board[i][j] = 0;
            }
        }

        impl(board, 0);
        return ans;
    }
};
#endif

// improve on backtracking, 4 ms
class Solution {
public:
    vector<vector<string>> ans;

    bool isValid(const vector<string> &board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') { // brilliant
                return false;
            }
            int left = col - (row - i);
            int right = col + (row - i);
            if (left >= 0 && board[i][left] == 'Q') {
                return false;
            }
            if (right < board.size() && board[i][right] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void backtracking(vector<string> &board, int n, int row) {
        if (n == row) {
            ans.emplace_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                backtracking(board, n, row + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        vector<string> board(n, string(n, '.'));
        backtracking(board, n, 0);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    auto vvstr = solution.solveNQueens(4);
    for (auto const& vstr : vvstr) {
        for (auto const& str : vstr) {
            cout << str << endl;
        }
        cout << endl;
    }
}