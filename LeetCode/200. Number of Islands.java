//https://leetcode.com/problems/number-of-islands/
class Solution {
	int[][] changePos = {{1,0},{-1,0}, {0,1}, {0,-1}};
	int row, column;
	
	public void DFS(int r, int c, boolean visited[][], char[][] grid) {
		visited[r][c] = true;
		
		int next_r, next_c;
		for(int i=0; i<changePos.length ; ++i) {
			next_r = r+changePos[i][0]; next_c = c+ changePos[i][1];
			
			if(next_r<0 || row<= next_r || next_c<0 || column <= next_c)
				continue;
			
			if(!visited[next_r][next_c] && grid[next_r][next_c] == '1') 
				DFS(next_r, next_c, visited, grid);
		}
	}
	
    public int numIslands(char[][] grid) {
    	row = grid.length; column = grid[0].length;
        boolean[][] visited = new boolean[row][column];
        
        int count_island = 0;
        for(int r=0; r<row ; ++r) 
        	for(int c=0; c<column ;++c) 
        		if(!visited[r][c] && grid[r][c] == '1') {
        			DFS(r,c, visited, grid);
        			++count_island;
        		}
        	
        return count_island;
    }
}
