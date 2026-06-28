class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(const auto &n : intervals) {

            if(!ans.empty() && ans.back()[1] >= n[0]) {
                ans.back()[1] = max(ans.back()[1], n[1]);
            }

            else {
                ans.push_back(n);
            }

        }

        return ans;
    }
};