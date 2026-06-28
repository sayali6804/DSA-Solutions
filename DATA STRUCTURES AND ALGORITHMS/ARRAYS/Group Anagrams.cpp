class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> ans;

        for(string s : strs) {

            string dup = s;

            sort(dup.begin(), dup.end());

            ans[dup].push_back(s);

        }

        vector<vector<string>> result;

        for(auto &a : ans) {
            result.push_back(a.second);
        }

        return result;
    }
};