class Solution {
public:
    void backtrack(int idx, vector<int>& candidates, int target, 
                   vector<int>& temp, vector<vector<int>>& result) {
        // Base condition: target reached
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        // If target becomes negative, stop exploring
        if (target < 0) return;

        // Explore from current index onwards
        for (int i = idx; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);                 // choose the number
            backtrack(i, candidates, target - candidates[i], temp, result); // stay at i (reuse allowed)
            temp.pop_back();                               // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(0, candidates, target, temp, result);
        return result;
    }
};
