class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();
        int left=0, right=n-1, i=0;

        while(i <= right) {

            if(a[i] == 0) {
                swap(a[i], a[left]);
                left++;
                i++;
            }

            else if(a[i] == 2) {
                swap(a[i], a[right]);
                right--;
            }

            else {
                i++;
            }
        }
    }
};