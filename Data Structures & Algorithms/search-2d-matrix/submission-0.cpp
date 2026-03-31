class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int outer_left = 0;
        int outer_right = matrix.size() - 1;
        int inner_left = 0;
        int inner_right = matrix[0].size() - 1;
        int candidate_row = 0;

        while (outer_left <= outer_right) {
            int outer_mid = outer_left + ((outer_right - outer_left) / 2);

            if (matrix[outer_mid][inner_left] == target || matrix[outer_mid][inner_right] == target) {
                return true;
            }
            else if (matrix[outer_mid][inner_left] > target) {
                outer_right = outer_mid - 1;
                continue;
            }
            else if (matrix[outer_mid][inner_right] < target) {
                outer_left = outer_mid + 1;
                continue;
            }
            else {
                candidate_row = outer_mid;
                break;
            }
        }

        while (inner_left <= inner_right) {
            int inner_mid = inner_left + ((inner_right - inner_left) / 2);

            if (matrix[candidate_row][inner_mid] > target) {
                inner_right = inner_mid - 1;
            }
            else if (matrix[candidate_row][inner_mid] < target) {
                inner_left = inner_mid + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
