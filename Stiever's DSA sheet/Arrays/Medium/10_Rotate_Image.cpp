/*
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i=0,j=0;
        int n=matrix[0].size();

        // transpose the matrix
        for(i=0;i<n;i++){
            for(j=0;j<=i;j++)
                swap(matrix[i][j],matrix[j][i]);
        }
       // swap the columns
        for(i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};
