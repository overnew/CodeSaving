class Solution {
private:
    stack<TreeNode*> pAncestors;
    stack<TreeNode*> qAncestors;

public:
    bool findAncestors(TreeNode* root, TreeNode* node, stack<TreeNode*>& ancestors) {
        if (root == nullptr)
            return false;
        
        if (root->val == node->val) {
            ancestors.push(root);
            return true;
        }

        if (findAncestors(root->left, node, ancestors) || findAncestors(root->right, node, ancestors)) {
            ancestors.push(root);
            return true;
        }
        
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findAncestors(root, p, pAncestors);
        findAncestors(root, q, qAncestors);

        TreeNode* lca = new TreeNode(1000000001);
        int len = min(pAncestors.size(), qAncestors.size());

        for (int i=0; i<len ; ++i) {
            TreeNode* pTop = pAncestors.top();  pAncestors.pop();
            TreeNode* qTop = qAncestors.top();  qAncestors.pop();

            if (pTop->val == qTop->val)
                lca = pTop;
        }
        return lca;
    }
};
