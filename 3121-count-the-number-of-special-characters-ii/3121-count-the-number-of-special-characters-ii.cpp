class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> mp;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch>='A' && ch<='Z'){
                if(!mp[ch]){
                    mp[ch]=i+1;
                }
            }
            else mp[ch]=i+1;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(mp['a'+i] && mp['A'+i] && mp['a'+i]<mp['A'+i]){
                ans++;
            }
        }
        return ans;
    }
};