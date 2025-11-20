/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// doing it using bfs traversal
    int bfs(TreeNode* root){
        //vector<vector<int>> ans;
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* t=q.front();
                q.pop();
                //temp.push_back(t->val);
                if(t->left!=NULL){
                    q.push(t->left);
                }
                if(t->right!=NULL){
                    q.push(t->right);
                }
            }
            if(!q.empty()){
                ans++;
            }
        }
        return ans;
    }

    int maxDepth(TreeNode* root) {
        return bfs(root);
    }
};