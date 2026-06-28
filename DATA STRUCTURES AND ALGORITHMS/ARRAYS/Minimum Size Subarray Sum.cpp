class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();

        int left = 0, mn = INT_MAX, sum = 0;

        for(int i = 0; i < n; i++) {
            
            sum += nums[i];

            while(sum >= target) {

                mn = min(mn, i - left + 1);
                sum -= nums[left++];

            }

        }

        return mn == INT_MAX ? 0 : mn;

    }
};