class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) // T.C. = O(i*j)  //USING LINEAR SEARCH
    {
        for(auto i:matrix){
            for(auto j:i){
                if(j==target) return true;
            }
        }
        return false;
    }
	
    bool searchMatrix(vector<vector<int>>& matrix, int target)    // T.C. = O(log(m+n))  //USING BINARY SEARCH
    {
       
       int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
        
     bool searchMatrix(vector<vector<int>>& matrix, int target) // T.C. = O(m+n)  //USING BINARY SEARCH TREE
     {
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
    }
};
