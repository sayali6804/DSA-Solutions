class Solution {
public:

    void generate(vector<int> &nums, int index, vector<int> &curr, vector<vector<int>> &res) {

        if(index == nums.size()) {
            res.push_back(curr);
            return;
        }

        // include current element

        curr.push_back(nums[index]);
        generate(nums, index + 1, curr, res);

        // exclude current element

        curr.pop_back();
        generate(nums, index + 1, curr, res);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        generate(nums, 0, curr, res);

        return res;
    }
};