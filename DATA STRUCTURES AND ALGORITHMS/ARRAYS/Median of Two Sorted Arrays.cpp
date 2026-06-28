class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int> c(a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());

        sort(c.begin(), c.end());

        int n = c.size();
        if (n % 2 == 1) {
            return c[n / 2];  // Odd case
        } else {
            return (c[n / 2] + c[(n / 2) - 1]) / 2.0;  // Even case
        }
    }
};