//https://leetcode.com/problems/pacific-atlantic-water-flow/
class Solution{
	class Pair {
		int r, c;
		Pair(){}
	    Pair(int r, int c){
	    	this.r = r;
	    	this.c = c;
	    }
	}
	
	int[][] changePos = {{0,1},{0,-1},{1,0},{-1,0}};
	
	public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int row = heights.length +2, column = heights[0].length +2;
        int[][] newHeights = new int[row][column];
        
        for(int r = 1; r< row-1; ++r) //가장자리에 바다를 추가한 새로운 heights배열
        	for(int c = 1; c<column-1 ; ++c) 
        		newHeights[r][c] = heights[r-1][c-1];
        
        //pacific BFS
        Queue<Pair> paciQue = new LinkedList<Pair>();
        boolean[][] paciVisited = new boolean[row][column];
        for(int i=1; i<row-1 ;++i) {
        	paciVisited[i][0] = true;
        	paciQue.add(new Pair(i,0));
        }
        for(int i=1; i<column-1 ;++i) {
        	paciVisited[0][i] = true;
        	paciQue.add(new Pair(0,i));
        }
        
        while(!paciQue.isEmpty()) {
        	Pair front = paciQue.poll();
        	int r = front.r, c = front.c;
        	int nowHeight =newHeights[r][c];
        	
        	for(int i=0; i<changePos.length ; ++i) {
        		int next_r = r + changePos[i][0], next_c = c  + changePos[i][1];
        		
        		//범위확인
        		if( next_r <1 || row -1 <= next_r || next_c <1 || column -1 <= next_c )
        			continue;
        		
        		if(!paciVisited[next_r][next_c] && nowHeight  <=newHeights[next_r][next_c]) {
        			paciVisited[next_r][next_c] = true;
        			paciQue.add(new Pair(next_r, next_c));
        		}
        	}		
        }
        
        //Atlantic BFS
        Queue<Pair> atlaQue = new LinkedList<Pair>();
        boolean[][] atlaVisited = new boolean[row][column];
        for(int i=1; i<row-1 ;++i) {
        	atlaVisited[i][column-1] = true;
        	atlaQue.add(new Pair(i,column-1));
        }
        for(int i=1; i<column-1 ;++i) {
        	atlaVisited[row-1][i] = true;
        	atlaQue.add(new Pair(row-1,i));
        }
        
        while(!atlaQue.isEmpty()) {
        	Pair front = atlaQue.poll();
        	int r = front.r, c = front.c;
        	int nowHeight =newHeights[r][c];
        	
        	for(int i=0; i<changePos.length ; ++i) {
        		int next_r = r + changePos[i][0], next_c = c  + changePos[i][1];
        		
        		//범위확인
        		if( next_r <1 || row -1 <= next_r || next_c <1 || column -1 <= next_c )
        			continue;
        		
        		if(!atlaVisited[next_r][next_c] && nowHeight  <=newHeights[next_r][next_c]) {
        			atlaVisited[next_r][next_c] = true;
        			atlaQue.add(new Pair(next_r, next_c));
        		}
        	}		
        }

        List<List<Integer>> answer = new ArrayList<List<Integer>>();
        for(int r=1; r < row-1 ; ++r) 
        	for(int c= 1; c< column -1 ; ++c) 
        		// 두 바다에서 모두 접근 가능하면 정답
        		if(paciVisited[r][c] && atlaVisited[r][c]) 
        			answer.add(new ArrayList<Integer>(Arrays.asList(r-1,c-1)));
        
        return answer;
    }
}
