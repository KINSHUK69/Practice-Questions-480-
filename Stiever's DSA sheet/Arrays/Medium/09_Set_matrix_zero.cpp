/*
Input: matrix =  [1,1,1]
                 [1,0,1]
                 [1,1,1]
Output:  [1,0,1]
         [0,0,0]
         [1,0,1]
*/
void setZeroes(int[][] matrix)    // T.C. = O(M*N*K)		S.C. = O(1)
{

	int m= matrix.length, n= matrix[0].length;
        int matrix2[][]= new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                matrix2[i][j]=matrix[i][j];
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<n;k++)
                        matrix2[i][k]=0;

                    for(int k=0;k<m;k++)
                        matrix2[k][j]=0;
                }
            }
        }
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                matrix[i][j]=matrix2[i][j];
        }
    }

//  T.C. = O(MN)		S.C. = O(M+N)
void setZeroes(vector<vector<int>>& matrix) {     
        int rowsize=matrix.size(); 
        int columnsize=matrix[0].size(); 
        vector<int>rowmarker(rowsize,1);
        vector<int>columnmarker(columnsize,1); 
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<columnsize;j++)
            {
                if(matrix[i][j]==0)
                {
                    rowmarker[i]=0; 
                    columnmarker[j]=0;
                }
            }
        } 
        for(int i=0;i<rowsize;i++)
        {
            for(int j=0;j<columnsize;j++)
            {
                if(rowmarker[i]==0 or columnmarker[j]==0)
                    matrix[i][j]=0;
             }
        }
        
    }


//  T.C. = O(MN)		S.C. = O(1)
void setZeroes(int[][] matrix)   
{
 int rows = matrix.size(), cols = matrix[0].size();
 bool col0=true;

    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
	    
        if (col0 == 0) matrix[i][0] = 0;
    }
}
