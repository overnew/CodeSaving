//https://leetcode.com/problems/course-schedule/
class Solution {
	public boolean canFinish(int numCourses, int[][] prerequisites) {
	    int[] indegree = new int[numCourses];
	    ArrayList<ArrayList<Integer>> adjList =new ArrayList<ArrayList<Integer>>();
	    for(int i=0; i<numCourses ; ++i)	//ArrayList초기화
	    	adjList.add(new ArrayList<Integer>());
	    
	    for(int i=0; i<prerequisites.length ; ++i) {
	    	int out = prerequisites[i][1], in = prerequisites[i][0];
	    	adjList.get(out).add(in);
	    	indegree[in]++;
	    }

	    boolean[] isVisited = new boolean[numCourses];
	    boolean[] isInQue = new boolean[numCourses];
	    
	    Queue<Integer> que = new LinkedList<>();
	    for(int i=0; i<numCourses ; ++i) {//진입차수가 0인 노드만 큐에 삽입
	    	if(indegree[i] == 0) {
	    		que.add(i);
	    		isInQue[i] = true;
	    	}
	    }
	    
	    while(!que.isEmpty()) { //BFS
	    	int idx = que.poll();
	    	isVisited[idx] = true;
	    	
	    	for(int adjNode: adjList.get(idx)) {
	    		if( (--indegree[adjNode]) ==0 &&!isInQue[adjNode]) {
	    			que.add(adjNode);
	    			isInQue[adjNode] = true;
	    		}
	    	}
	    }
	    
	    for(int i=0; i<numCourses ;++i) 
	    	if(!isVisited[i])
	    		return false;
		
		return true;
	}
}
