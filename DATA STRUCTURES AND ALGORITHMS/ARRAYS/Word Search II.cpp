class Solution {
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word; // store full word at the end node
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return; // visited or not in trie
        node = node->children[c - 'a'];

        if (!node->word.empty()) {  // found a word
            result.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[i][j] = '#'; // mark visited

        int m = board.size(), n = board[0].size();
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && nj >= 0 && ni < m && nj < n)
                dfs(board, ni, nj, node, result);
        }

        board[i][j] = c; // backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        // 1️⃣ Build Trie
        for (auto& w : words) insertWord(root, w);

        vector<string> result;
        int m = board.size(), n = board[0].size();

        // 2️⃣ DFS from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};
