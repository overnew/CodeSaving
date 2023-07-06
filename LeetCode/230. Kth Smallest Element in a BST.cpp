class Solution {
public:
    int K = -1;
    int cnt = 0;

    int visitInorderK(TreeNode* root) {

        if (root->left != nullptr) {
            int result = visitInorderK(root->left);
            if (result != -1)
                return result;
        }

        if (++cnt == K)
            return root->val;

        if (root->right != nullptr) {
            int result = visitInorderK(root->right);
            if (result != -1)
                return result;
        }

        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        K = k;
        return visitInorderK(root);
    }
};
