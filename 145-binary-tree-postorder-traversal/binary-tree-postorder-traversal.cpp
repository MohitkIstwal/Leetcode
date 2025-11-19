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

    void postorder(vector<int> &v,TreeNode* root){
        if(!root){
            return;
        }
        postorder(v,root->left);
        postorder(v,root->right);
        v.push_back(root->val);
    }
// iterative using 1 stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        TreeNode* cur=root;
        TreeNode* temp;
        stack<TreeNode*> st;
        while(!st.empty() || cur!=NULL){
            if(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            else{
                temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    cur=temp;
                }
            }
        }
        return ans;
    }
};