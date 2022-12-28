class Solution {
private:
    int maxSum = -1000;

public:
    int maxPathSum(TreeNode* root) {
        DFS(root);
        return maxSum;
    }

    int DFS(TreeNode* root) {
        if (root == NULL)
            return  0;

        int leftPathSum = DFS(root->left);
        int rightPathSum = DFS(root->right);

        int rootMaxSum = leftPathSum + rightPathSum + root->val;
        int ret = max({leftPathSum + root->val, rightPathSum + root->val, root->val });
        maxSum = max({ maxSum, rootMaxSum ,ret });

        return ret;
    }
};
