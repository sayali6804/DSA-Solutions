class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int lt = i + 1, rt = n - 1;

            while(lt < rt) {
                int sum = nums[i] + nums[lt] + nums[rt];
                
                if(sum == 0) {
                    res.push_back({nums[i], nums[lt], nums[rt]});

                    while(lt < rt && nums[lt] == nums[lt + 1]) {
                        lt++;
                    }

                    while(lt < rt && nums[rt] == nums[rt - 1]) {
                        rt--;
                    }

                    lt++;
                    rt--;
                }

                else if(sum < 0) {
                    lt++;
                }

                else {
                    rt--;
                }
            }

        }

        return res;
    }
};