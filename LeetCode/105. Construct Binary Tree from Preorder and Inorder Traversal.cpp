class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;

        int rootVal = preorder[0];  //pre의 첫 노드가 root노드
    
        int idx = 0;
        for (; idx<inorder.size(); idx++) {
            if (inorder[idx] == rootVal)
                break;
        }

        int leftSubTreeSize = idx, rightSubTreeSize = inorder.size() - (leftSubTreeSize +1);

        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        if (leftSubTreeSize <= 0 && rightSubTreeSize <=0) {
            return new TreeNode(rootVal);
        }

        if (leftSubTreeSize > 0) {
            vector<int> leftSubPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftSubTreeSize );
            vector<int> leftSubInorder(inorder.begin(), inorder.begin() + leftSubTreeSize );
            left = buildTree(leftSubPreorder, leftSubInorder);
        }

        if (rightSubTreeSize > 0) {
            vector<int> rightSubPreorder(preorder.begin() + 1 + (leftSubTreeSize), preorder.end());
            vector<int> rightSubInorder(inorder.begin() + leftSubTreeSize + 1, inorder.end());
            right = buildTree(rightSubPreorder, rightSubInorder);
        }

        TreeNode* root = new TreeNode(rootVal, left, right);
        return root;
    }
};
