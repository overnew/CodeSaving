class Solution {
public:

    bool isSubtreeFromNotRoot(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr)  //둘다 null인 경우 합격
            return true;

        if (root == nullptr || subRoot == nullptr)  //한쪽만 null인 경우
            return false;

        if (root->val == subRoot->val){
            if (isSubtreeFromNotRoot(root->left, subRoot->left)
                && isSubtreeFromNotRoot(root->right, subRoot->right))
                return true;
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr)  //둘다 null인 경우 합격
            return true; 

        if (root == nullptr || subRoot == nullptr)  //한쪽만 null인 경우
            return false;

        if (root->val == subRoot->val) {
            if (isSubtreeFromNotRoot(root->left, subRoot->left)
                && isSubtreeFromNotRoot(root->right, subRoot->right))
                return true;
            else {
                if (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot))
                    return true;
            }
        }
        else {
            if(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot))
                return true;
        }

        return false;
    }
};
