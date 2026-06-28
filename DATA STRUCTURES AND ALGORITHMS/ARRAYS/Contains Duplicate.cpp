#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                // Duplicate found
                return true;
            }
            seen.insert(num);
        }
        
        // No duplicates found
        return false;
    }
};
