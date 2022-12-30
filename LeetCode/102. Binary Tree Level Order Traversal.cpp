class Solution {
 public:
     vector<vector<int>> levelOrder(TreeNode* root){
         vector<vector<int>> ret;

         if (root == NULL)
            return ret;

         queue<pair<int,TreeNode*>> que;
         que.push({1,root});

         while (!que.empty() ) {
             pair<int, TreeNode*> data = que.front();
             que.pop();

             if (ret.size() < data.first)   //새로운 레벨 추가
                 ret.push_back(vector<int>());

             ret[data.first-1].push_back(data.second->val);
             
             if(data.second->left != NULL)
                que.push({data.first +1,data.second->left });

             if (data.second->right != NULL)
                que.push({ data.first + 1,data.second->right});

         }

         return ret;
     }

 };
