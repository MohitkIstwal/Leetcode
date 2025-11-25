class Solution {
public:

    void helper(vector<string> &v,int &n,int ind,string &s){
        if(ind==n){
            v.push_back(s);
            return;
        }
        
        s[ind]='(';
        helper(v,n,ind+1,s);
        
        s[ind]=')';
        helper(v,n,ind+1,s);
    }

    void reducer(vector<string> &v,vector<string> &fans){
        for(auto str: v){
            string s=str;
            int n=str.size();
            int a=0;
            for(int i=0;i<n;i++){
                if(s[i]=='('){
                    a++;
                }
                else{
                    a--;
                }
                if(a<0){
                    break;
                }
            }
            if(a==0){
                fans.push_back(s);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int ind=0;
        string s;
        n*=2;
        for(int i=0;i<n;i++){
            s.push_back('0');
        }
       
        helper(v,n,ind,s);
        vector<string> fans;
        reducer(v,fans);
        return fans;
    }
};