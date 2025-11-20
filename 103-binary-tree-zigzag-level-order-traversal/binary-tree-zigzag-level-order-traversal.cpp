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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> temp(n);
            for(int i=0;i<n;i++){
                TreeNode* t=q.front();
                q.pop();

                if(flag==0){
                    temp[i]=t->val;
                }
                else{
                    temp[n-i-1]=t->val;
                }

                if(t->left!=NULL){
                    q.push(t->left);
                }
                if(t->right!=NULL){
                    q.push(t->right);
                }
            }
            ans.push_back(temp);
            if(flag==0){
                flag++;
            }
            else{
                flag--;
            }
        }
        return ans;
    }
};