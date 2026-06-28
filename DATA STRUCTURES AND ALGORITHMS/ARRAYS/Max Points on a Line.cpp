#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 1) return points.size();
        
        int maxCount = 1; // At least one point is always on a line
        
        for (int i = 0; i < points.size(); i++) {
            unordered_map<string, int> slopeMap;
            int samePoint = 0, localMax = 0;
            
            for (int j = i + 1; j < points.size(); j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if (dx == 0 && dy == 0) {
                    samePoint++; // Same point
                    continue;
                }

                int gcdVal = __gcd(dx, dy);
                dx /= gcdVal;
                dy /= gcdVal;
                
                // Store slope as a string to handle negative slopes
                string slope = to_string(dy) + "/" + to_string(dx);
                slopeMap[slope]++;
                
                localMax = max(localMax, slopeMap[slope]);
            }
            
            maxCount = max(maxCount, localMax + samePoint + 1);
        }
        
        return maxCount;
    }
};
