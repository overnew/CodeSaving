//https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
	class Node{
		int num;
		Node left=null, right = null;
		boolean visited = false;
		Node(int num){
			this.num = num;
		}
	}
	
	public int longestConsecutive(int[] nums) {
		Map<Integer, Node> map = new HashMap<>();
		
		//그래프 생성
		for(int n: nums) {
			if(map.containsKey(n))
				continue;
			
			Node newNode = new Node(n);
			map.put(n, newNode);
			if(map.containsKey(n-1)) {
				Node leftNode = map.get(n-1);
				leftNode.right = newNode;
				newNode.left = leftNode;
			}
			
			if(map.containsKey(n+1)) {
				Node rightNode = map.get(n+1);
				rightNode.left = newNode;
				newNode.right = rightNode;
			}
		}
		
		//그래프 순회
		int max_size=0;
		for(int n: nums) {
			Node node = map.get(n);
			if(!node.visited) {
				node.visited = true;
				
				int leftSize =0, rightSize = 0;
				Node leftNode = node.left, rightNode = node.right;
				
				while(leftNode != null) {
					leftSize++;
					leftNode.visited= true;
					leftNode = leftNode.left;
				}
				while(rightNode != null) {
					rightSize++;
					rightNode.visited = true;
					rightNode = rightNode.right;
				}
				
				max_size = Math.max(leftSize + rightSize + 1, max_size);
			}
		}
        return max_size;
    }
}
