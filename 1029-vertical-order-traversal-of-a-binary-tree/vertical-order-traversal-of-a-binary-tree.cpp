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

    //nice question - implementational
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> node;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* t=q.front().first;
            int x=q.front().second.first,y=q.front().second.second;
            node[x][y].insert(t->val);
            q.pop();
            if(t->left){
                q.push({t->left,{x-1,y+1}});
            }
            if(t->right){
                q.push({t->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto it: node){
            vector<int> temp;
            for(auto val: it.second){
                for(auto item: val.second){
                    temp.push_back(item);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};