class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;

        int n = nums.size();

        if(n == 0) {
            return res;
        }

        for(int i = 0; i < nums.size(); i++) {
            int s = nums[i];
            while(i + 1 < n && nums[i + 1]  == nums[i] + 1) {
                i++;
            }

            if(s == nums[i]) {
                res.push_back(to_string(s));
            }

            else {
                res.push_back(to_string(s) + "->" + to_string(nums[i]));
            }
        }
        return res;
    }
};