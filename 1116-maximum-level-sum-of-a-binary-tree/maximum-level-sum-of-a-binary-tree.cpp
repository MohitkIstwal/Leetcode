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

    // just use bfs and maintain the level with max sum
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *> q;
        TreeNode* node=root;
        q.push(node);
        int sum=0,mmax=-1e9,level=1,ans=0;
        while(!q.empty()){
            int size=q.size();
            sum=0;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(sum>mmax){
                mmax=sum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};