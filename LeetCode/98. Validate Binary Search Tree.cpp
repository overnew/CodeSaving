class Solution {
public:
    bool insertNodeToBST(TreeNode* root, int nodeVal) {
        int rootVal = root->val;
        if (rootVal < nodeVal) {
            if (root->right == nullptr) {
                root->right = new TreeNode(nodeVal);;
                return true;
            }
            
            insertNodeToBST(root->right, nodeVal);
        }
        else if(rootVal > nodeVal) {
            if (root->left == nullptr) {
                root->left = new TreeNode(nodeVal);
                return true;
            }

            insertNodeToBST(root->left, nodeVal);
        }
        else {
            return false;
        }

        return true;
    }

    TreeNode* makeBST(vector<int> treeVal) {
        TreeNode* root = new TreeNode(treeVal[0]);
        for (auto it = treeVal.begin() +1; it!= treeVal.end(); it++) {
            if (!insertNodeToBST(root, *it))
                return nullptr;
        }

        return root;
    }

    vector<int> travelTreeBFS(TreeNode* root) {
        vector<int> treeVals;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            if (node == nullptr) {  //null 처리
                continue;
            }

            int val = node->val;
            treeVals.push_back(node->val);

            que.push(node->left);
            que.push(node->right);
        }

        return treeVals;
    }

    bool checkBSTIsSame(TreeNode* targetRoot, TreeNode* BstRoot) {
        if (targetRoot == nullptr && BstRoot == nullptr)
            return true;

        if (targetRoot == nullptr && BstRoot != nullptr)
            return false;

        if (targetRoot != nullptr && BstRoot == nullptr)
            return false;

        if (targetRoot->val != BstRoot->val)
            return false;

        if (!checkBSTIsSame(targetRoot->left, BstRoot->left))
            return false;

        if (!checkBSTIsSame(targetRoot->right, BstRoot->right))
            return false;

        return true;
    }

    bool isValidBST(TreeNode* root) {
        vector<int> treeVals = this->travelTreeBFS(root);
        TreeNode* bstRoot=this->makeBST(treeVals);

        if (bstRoot == nullptr)
            return false;

        return this->checkBSTIsSame(root,bstRoot);
    }
};
