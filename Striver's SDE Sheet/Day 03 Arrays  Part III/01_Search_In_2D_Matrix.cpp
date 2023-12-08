
class Solution {
public:
    // Using Binary Search
    // T.C. = O(log m*n)
    // S.C. = O(1)

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        int r = 0,c = colSize-1;
        while(r<rowSize && c>-1){
            int curr = matrix[r][c];

            if(curr == target) return true;
            if(target > curr) r++;
            else c--;
        }
        return false;
    }
};
