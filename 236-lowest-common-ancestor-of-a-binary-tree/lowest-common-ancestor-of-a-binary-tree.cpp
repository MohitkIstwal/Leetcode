/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool getpath(TreeNode* root,int x,vector<TreeNode*> &ans){
        if(root==NULL){
            return false;
        }
        ans.push_back(root);
        if(root->val==x){
            return true;
        }
        if(getpath(root->left,x,ans) || getpath(root->right,x,ans)){
            return true;
        }
        ans.pop_back();
        return false;
    }

    //using the path method that we learnt in prev question
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr;
        getpath(root,p->val,arr);
        vector<TreeNode*> arr1;
        getpath(root,q->val,arr1);
        for(int i=0;i<max(arr.size(),arr1.size());i++){
            if(i==arr.size()){
                return arr[i-1];
            }
            else if(i==arr1.size()){
                return arr1[i-1];
            }
            int a=arr[i]->val,b=arr1[i]->val;
            if(a!=b){
                return arr[i-1];
            }
        }
        return NULL;
    }
};