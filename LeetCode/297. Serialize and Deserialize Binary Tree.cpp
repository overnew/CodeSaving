struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:
    string NULL_STR = "null";

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (root == NULL)
            return "[]";

        queue<TreeNode*> que;
        vector<string> values;

        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            if (node == NULL) {
                values.push_back(NULL_STR);
                continue;
            }

            values.push_back(to_string(node->val));

            que.push(node->left);
            que.push(node->right);
        }

        string ret = "[";
        vector<string>::iterator it = values.begin();
        for (; it != values.end(); ++it) {
            ret.append(*it + ",");
        }
        ret.pop_back();
        ret.append("]");

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data.pop_back();    //"]"제거
        vector<string> values;
        stringstream sstream(data.substr(1));
        string val;

        while (getline(sstream, val, ','))  //parsing
            values.push_back(val);

        if (values.empty())
            return NULL;

        vector<string>::iterator it = values.begin();

        queue<TreeNode*> que;
        if ((*it).compare(NULL_STR) == 0)
            return NULL;

        TreeNode* rootNode = new TreeNode(stoi(*it));
        que.push(rootNode);
        ++it;

        while (!que.empty() && it != values.end()) {
            TreeNode* node = que.front();
            que.pop();

            if ((*it).compare(NULL_STR) != 0) {
                TreeNode* leftNode = new TreeNode(stoi(*it));
                node->left = leftNode;
                que.push(leftNode);
            }
            ++it;

            if ((*it).compare(NULL_STR) != 0) {
                TreeNode* rightNode = new TreeNode(stoi(*it));
                node->right = rightNode;
                que.push(rightNode);
            }
            ++it;
        }

        return rootNode;
    }
};
