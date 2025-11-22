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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=-1;
        while(!q.empty()){
            int size=q.size();
            int mmin=q.front().second;
            int first=-1,last=-1;
            for(int i=0;i<size;i++){
                TreeNode* t=q.front().first;
                int ind=q.front().second-mmin;
                q.pop();
                if(i==0){
                    first=ind;
                }
                if(i==size-1){
                    last=ind;
                }
                if(t->left){
                    q.push({t->left,(long long)2*ind+1});
                }
                if(t->right){
                    q.push({t->right,(long long)2*ind+2});
                }

            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};