class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (vector<char> row : board) {
            unordered_set<char> row_nums;

            for (char num : row) {
                auto it = row_nums.find(num);
                if (it == row_nums.end()) {
                    row_nums.insert(num);
                }
                else {
                    if (num != '.') {
                        return false;
                    }
                }
            }
        }

        for (int i=0; i<9; i++) {
            unordered_set<char> col_nums;

            for (int j=0; j<9; j++) {
                auto it = col_nums.find(board[j][i]);
                if (it == col_nums.end()) {
                    col_nums.insert(board[j][i]);
                }
                else {
                    if (board[j][i] != '.') {
                        return false;
                    }
                }
            }
        }

        for (int row_it=0; row_it<9; row_it+=3) {
            for (int col_it=0; col_it<9; col_it+=3) {
                unordered_set<char> block_nums;

                for (int i=0; i<3; i++) {
                    for (int j=0; j<3; j++) {
                        auto it = block_nums.find(board[row_it+i][col_it+j]);
                        if (it == block_nums.end()) {
                            block_nums.insert(board[row_it+i][col_it+j]);
                        }
                        else {
                            if (board[row_it+i][col_it+j] != '.') {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};
