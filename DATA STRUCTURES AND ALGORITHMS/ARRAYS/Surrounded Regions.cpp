class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        auto dfs = [&](int r, int c, auto&& dfs_ref) -> void {
            if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] != 'O' || vis[r][c])
                return;
            vis[r][c] = 1;
            board[r][c] = '#'; // mark safe
            dfs_ref(r + 1, c, dfs_ref);
            dfs_ref(r - 1, c, dfs_ref);
            dfs_ref(r, c + 1, dfs_ref);
            dfs_ref(r, c - 1, dfs_ref);
        };

        // Mark all border-connected 'O's as safe
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(i, 0, dfs);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, dfs);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(0, j, dfs);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, dfs);
        }

        // Convert surrounded 'O' → 'X' and safe '#' → 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
