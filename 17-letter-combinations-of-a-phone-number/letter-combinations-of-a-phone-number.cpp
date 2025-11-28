class Solution {
public:
    //whats going on
    //each digit from 2-9 represents some alphabets
    //we have to give combinations regarding the digit
    //got it
    //simply create vectors for strings 2-9 and insert with char that are designated to them
    //then simply recurse
    //base case is simply string size becomes equal to s
    //transtion is to next ind of the string

    void helper(int ind,string &digits,string &s,vector<string> &ans,map<char,vector<char>> &mp){
        if(ind==digits.size()){
            if(s.size()){
                ans.push_back(s);
            }
            return;
        }
        char ch=digits[ind];
        vector<char> v=mp[ch];
        //cout<<v.size()<<" ";
        for(int i=0;i<v.size();i++){
            s.push_back(v[i]);
            helper(ind+1,digits,s,ans,mp);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> mp;
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        vector<string> ans;
        string s="";
        helper(0,digits,s,ans,mp);
        return ans;
    }
};