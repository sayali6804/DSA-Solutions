class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;

        int r = matrix.size();

        int c = matrix[0].size();

        int total_elements = r * c;

        int sr = 0;
        int er = r-1;
        int sc = 0;
        int ec = c-1;

        int count = 0;

        while(count < total_elements ) {

            // print first row

            for(int i=sc; i <= ec && count < total_elements; i++) {
                
                ans.push_back(matrix[sr][i]);
                count++;

            }

            sr++;

            // print last column

            for(int i=sr; i<=er && count < total_elements; i++ ) {
                
                ans.push_back(matrix[i][ec]);
                count++;

            }

            ec--;

            //print last row

            for(int i=ec; i>=sc && count < total_elements; i-- ) {

                ans.push_back(matrix[er][i]);
                count++;

            }

            er--;

            // print first column

            for(int i=er; i>=sr && count < total_elements; i-- ) {

                ans.push_back(matrix[i][sc]);
                count++;

            }

            sc++;

        }

        return ans;

    }
};