//https://leetcode.com/problems/insert-interval/
class Solution{
  public int[][] insert(int[][] intervals, int[] newInterval) {
		if(intervals.length == 0) 
			return new int[][] {newInterval};
		
		    //newInterval이 삽입되야 하는 부분을 찾음
        int insertStart = newInterval[0];
        int insertIdx = 0;
        if(insertStart > intervals[0][0]) {
        	insertIdx = intervals.length;
        	for(int i=0; i<intervals.length-1 ; ++i) 
        		if(intervals[i][0] <= insertStart && insertStart <= intervals[i+1][0])
        			insertIdx = i+1;
        }
        	
        int[][] insertedIntervals = new int[intervals.length+1][2];
        
        for(int i=0; i<insertIdx ; ++i) 
        	insertedIntervals[i] = intervals[i];
        insertedIntervals[insertIdx] = newInterval;
        for(int i=insertIdx; i<intervals.length ; ++i) 
        	insertedIntervals[i+1] = intervals[i];
        
        //구간이 겹치는 부분을 저장
        ArrayList<int[]> overlap = new ArrayList<>();
        
        int start = insertedIntervals[0][0], end = insertedIntervals[0][1];
        for(int idx = 1 ; idx< insertedIntervals.length ; ++idx) {
        	if(insertedIntervals[idx][0] <= end) {	//합쳐지는 경우
        		end = Math.max(end,insertedIntervals[idx][1]);
        	}else {		// 합쳐지지 않는 경우 삽입
        		overlap.add(new int[] {start,end});
        		start = insertedIntervals[idx][0];
        		end = insertedIntervals[idx][1];
        	}
        }
        overlap.add(new int[] {start,end});
        
        int[][] answer = new int[overlap.size()][2];
        for(int i=0; i<overlap.size() ; ++i) 
        	answer[i] = overlap.get(i);
        
        
        return answer;
    }
}
