class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1) {
            return 0;
        }

        int jmp = 0, end = 0, f = 0;

        for(int i = 0; i < n - 1; i++) {
            f = max(f, i + nums[i]);

            if(i == end) {
                jmp++;
                end = f;

                if(end >= n - 1) {
                    break;
                }
            }
        }

        return jmp;
    }
};