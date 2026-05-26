class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> mp;
        for(char ch: word){
            mp[ch]++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(mp['a'+i] && mp['A'+i]){
                ans++;
            }
        }
        return ans;
    }
};