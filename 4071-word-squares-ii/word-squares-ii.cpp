class Solution {
public:
    // okay so basic idea is backtracking
    // using recursion to check all 4 strings pair

    bool isvalid(vector<string> &v){
        string t=v[0],l=v[1],r=v[2],b=v[3];
        if(t[0]==l[0] && t[3]==r[0] && b[0]==l[3] && b[3]==r[3]){
            return true;
        }
        return false;
    }

    void helper(vector<string> &cur,vector<vector<string>> &ans,vector<string> &arr,vector<int> &used){
        if(cur.size()==4){
            if(isvalid(cur)){
                ans.push_back(cur);
            }
            return;
        }
        for(int i=0;i<arr.size();i++){
            if(used[i]){
                continue;
            }
            used[i]=1;
            cur.push_back(arr[i]);
            helper(cur,ans,arr,used);
            cur.pop_back();
            used[i]=0;
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        vector<string> arr=words;
        vector<int> used(words.size(),0);

        vector<string> cur;
        helper(cur,ans,arr,used);

        sort(ans.begin(),ans.end());

        return ans;
    }
};