//https://leetcode.com/problems/merge-k-sorted-lists/
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>(new Comparator<ListNode>() {
        	@Override
			public int compare(ListNode o1, ListNode o2) {
				return o1.val - o2.val;
			}
        });
        
        for(int i=0; i< lists.length ; ++i) {
        	if(lists[i] != null)
        		pq.add(lists[i]);
        }
        
        ListNode dummyHead = new ListNode();
        ListNode currNode = dummyHead;
        
        while(!pq.isEmpty()) {
        	ListNode node = pq.poll();
        	
        	if(node.next != null)
        		pq.add(node.next);
        	
        	currNode.next = node;
        	currNode = currNode.next;
        }
        
        return dummyHead.next;
    }
}
