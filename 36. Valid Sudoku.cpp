#include <vector>

using namespace std;

class Solution {
public:
    int occ_row[9];
    int occ_col[9][9];
    int occ_blk[3][9];

    void clear_occ_row() {
        for (int i = 0; i < 9; ++i) {
            occ_row[i] = 0;
        }
    }

    void clear_occ_col() {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                occ_col[i][j] = 0;
            }
        }
    }

    void clear_occ_blk() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 9; ++j) {
                occ_blk[i][j] = 0;
            }
        }
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        clear_occ_col();
        for (int row = 0; row < 9; ++row) {
            clear_occ_row();
            if (row % 3 == 0) {
                clear_occ_blk();
            }
            for (int col = 0; col < 9; ++col) {
                // occ_row
                char ch = board[row][col];
                if (ch == '.') {
                    continue;
                }
                if (occ_row[ch - '1']) {
                    return false;
                }
                occ_row[ch - '1'] = 1;
                // occ_col
                if (occ_col[col][ch - '1']) {
                    return false;
                }
                occ_col[col][ch - '1'] = 1;
                // occ_blk
                int blk = col / 3;
                if (occ_blk[blk][ch - '1']) {
                    return false;
                }
                occ_blk[blk][ch - '1'] = 1;
            }
        }
        return true;
    }
};