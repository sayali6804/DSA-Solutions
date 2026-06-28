class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        unordered_map<int, int> mp;

        int i = 0;

        for(int n : nums) {

            if(mp[n] < 2) {
                nums[i++] = n;
                mp[n]++;
            }

        }

        return i;

    }
};