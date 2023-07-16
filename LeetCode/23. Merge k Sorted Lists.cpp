struct ListNode {
      int val;
        ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 struct ListCapsule {
     int val;
     ListNode* node;
     ListCapsule(int _val, ListNode* _node) : val(_val), node(_node) {}
 
     bool operator<(const ListCapsule& cap) const {
         return this->val > cap.val;
    }
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        priority_queue<ListCapsule> pq;

        for (ListNode* node : lists)
            if(node != nullptr)
                pq.push(ListCapsule(node->val, node));

        if (pq.empty())
            return nullptr;

        ListNode* root = pq.top().node;
        ListNode* cur = root;
        pq.pop();

        if(cur->next != nullptr)
            pq.push(ListCapsule(cur->next->val, cur->next));

        while (!pq.empty()) {
            ListNode* next_node = pq.top().node;
            pq.pop();

            cur->next = next_node;
            cur = next_node;

            if (cur->next != nullptr)
                pq.push(ListCapsule(cur->next->val, cur->next));
        }
        
        return root;
    }
};
