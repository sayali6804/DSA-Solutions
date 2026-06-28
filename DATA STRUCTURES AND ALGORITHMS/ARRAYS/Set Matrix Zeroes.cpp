class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRow = false, firstCol = false;

        // Step 1: Check if first row and first column need to be zeroed
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) firstCol = true;
        }
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) firstRow = true;
        }

        // Step 2: Use first row and column as markers for rest of matrix
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 3: Zero out cells based on markers
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Step 4: Zero out first row and column if needed
        if (firstRow) {
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        }
        if (firstCol) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};
