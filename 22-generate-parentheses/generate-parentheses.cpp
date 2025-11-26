class Solution {
public:

    void helper(vector<string> &v,int open,int close,int n,string &s){
        if(close==n){
            v.push_back(s);
            return;
        }

        if(open<n){
            s.push_back('(');
            helper(v,open+1,close,n,s);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            helper(v,open,close+1,n,s);
            s.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s="";
        int open=0,close=0;
        helper(v,open,close,n,s);
        return v;
    }
};