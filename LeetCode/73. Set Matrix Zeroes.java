//https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
   public static void fillColumnToZero(int[][] matrix,int row_len, int column_idx) {
		for(int r=0; r<row_len ; ++r) 
			matrix[r][column_idx] = 0;
	}
	
	public static void fillRowToZero(int[][] matrix,int col_len, int row_idx) {
		for(int c=0; c<col_len ; ++c) 
			matrix[c][row_idx] = 0;
	}
	
	public void setZeroes(int[][] matrix) {
		int row = matrix.length;
		int column = matrix[0].length;
		boolean first_col = false, first_row =false;
		
		for(int c=0; c<column ; ++c) 
			if(matrix[0][c] ==0)
				first_row = true;
		
		for(int r = 0; r<row ; ++r) {
			if(matrix[r][0] ==0)
				first_col = true;
				
			for(int c=1; c<column ; ++c) {
				if(matrix[r][c] ==0) {
					matrix[r][0] = 0;
					matrix[0][c] = 0;
				}
			}
		}
		
		for(int c=1; c < column ; ++c) 
			if(matrix[0][c] ==0) 
				fillColumnToZero(matrix, row, c);
		
		for(int r=1; r < row; ++r) 
			if(matrix[r][0] ==0) 
				fillRowToZero(matrix, column, r);
		
		if(first_col) 
			fillColumnToZero(matrix, row, 0);
		
		if(first_row) 
			fillRowToZero(matrix, column, 0);
		
    }
}
