class NumMatrix {
public:
 vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix) {  
        int rows=matrix.size();
        int cols=matrix[0].size();
      prefix=vector<vector<int>>(rows, vector<int>(cols, 0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int top= i>0?prefix[i-1][j]:0;
                int left= j>0?prefix[i][j-1]:0;
                int topleft= i>0 && j>0 ? prefix[i-1][j-1]:0;

                prefix[i][j]=matrix[i][j]+top+left-topleft;
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total=prefix[row2][col2];

        int top = row1>0 ?prefix[row1-1][col2]:0;
        int left= col1>0 ?prefix[row2][col1-1]:0;
        int topleft=row1>0 && col1 >0 ?prefix[row1-1][col1-1]:0;

        int sum=total-top-left+topleft;
        return sum;
    }
};
 