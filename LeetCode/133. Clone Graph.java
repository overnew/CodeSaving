class Solution {
 public Node cloneGraph(Node node) {
	 if(node == null)
		 return null;
	 
	 Map<Node, Node> map = new HashMap<>();
	 Queue<Node> que = new LinkedList<>();
	 map.put(node, new Node(node.val));
	 que.add(node);
	 
	 while(!que.isEmpty()) {
		 Node currNode = que.poll();
		 Node cloneNode = map.get(currNode);
		 
		 for(Node adjNode: currNode.neighbors) {
			 if(!map.containsKey(adjNode)) {
				 map.put(adjNode, new Node(adjNode.val));
				 que.add(adjNode);
			 }
			 cloneNode.neighbors.add(map.get(adjNode));
		 }
	 }
     
     return map.get(node);
 }
}
