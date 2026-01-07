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

    // calculate the total sum using simple dfs traversal
    // then calculate sum of each subtree and maintain max of totalsum-(totalsum-cursum)
    // at last ans will be in long long format give ans modulo 1e9+7
    long long totalsum=0;
    long long ans=0;
    const int MOD= 1e9+7;

    long long getsum(TreeNode* root){
        if(!root){
            return 0;
        }
        return root->val+getsum(root->left)+getsum(root->right);
    }

    long long calcursum(TreeNode* root){
        if(!root){
            return 0;
        }
        long long l=calcursum(root->left);
        long long r=calcursum(root->right);

        long long cursum=root->val+l+r;

        ans=max(ans,cursum*(totalsum-cursum));

        return cursum;
    }

    int maxProduct(TreeNode* root) {
        totalsum=getsum(root);
        calcursum(root);
        return ans%MOD;
    }
};