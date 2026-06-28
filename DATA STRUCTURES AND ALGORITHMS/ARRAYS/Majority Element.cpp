class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        int start = 0, end = n - 1;

        return nums[((start) + (end - start) / 2)];
    }
};