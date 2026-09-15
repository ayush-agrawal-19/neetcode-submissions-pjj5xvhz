class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i=0; i<9; i++) {
            unordered_map<char, int> rows;
            for (int j=0; j<9; j++) {
                if (board[i][j] != '.' && rows.contains(board[i][j])) {
                    cout << "row has duplicate" << endl;
                    return false;
                }
                else {
                    rows[board[i][j]] = 1;
                }
            }
        }

        for (int i=0; i<9; i++) {
            unordered_map<char, int> columns;
            for (int j=0; j<9; j++) {
                if (board[j][i] != '.' && columns.contains(board[j][i])) {
                    cout << "column has duplicate" << endl;
                    return false;
                }
                else {
                    columns[board[j][i]] = 1;
                }
            }
        }

        for (int row_it=0; row_it<9; row_it+=3) {
            for (int col_it=0; col_it<9; col_it+=3) {
                unordered_map<char, int> squares;

                for (int i=row_it; i<row_it+3; i++) {
                    for (int j=col_it; j<col_it+3; j++) {
                        if (board[i][j] != '.' && squares.contains(board[i][j])) {
                            cout << "square has duplicate" << endl;
                            return false;
                        }
                        else {
                            squares[board[i][j]] = 1;
                        }
                    }
                }
            }
        }

        return true;
    }
};
