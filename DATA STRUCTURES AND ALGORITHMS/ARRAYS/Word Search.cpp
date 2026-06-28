class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Check each cell in the board as a starting point
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int index) {
        // Check if the entire word has been found
        if (index == word.size()) return true;
        
        // Check boundaries and if the current cell matches the character in the word
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        // Mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '#';  // Use a special character to mark visited
        
        // Explore all 4 directions
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);
        
        // Unmark the cell (backtrack)
        board[i][j] = temp;
        
        return found;
    }
};