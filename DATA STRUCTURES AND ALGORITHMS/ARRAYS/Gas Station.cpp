class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int tt = 0, ct = 0, start = 0;

        for(int i = 0; i < gas.size(); i++) {

            tt += gas[i] - cost[i];
            ct += gas[i] - cost[i];

            if(ct < 0) {
                ct = 0;
                start = i + 1;
            }

        }

        return tt >= 0 ? start : -1;
    }
};