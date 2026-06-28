class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();

        k %= n;

        vector<int> ans;

        ans.insert(ans.end(), nums.begin() + (n - k), nums.end());
        ans.insert(ans.end(), nums.begin(), nums.begin() + (n - k));

        nums = ans;

    }
};