class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        vector<pair<int,int>> v(26);
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a'].first==0){
                v[s[i]-'a'].first=i+1;
            }
            v[s[i]-'a'].second=i+1;
        }
        for(auto it: v){
            set<char> st;
            if(it.second){
                for(int i=it.first;i<it.second-1;i++){
                    st.insert(s[i]);
                }
                ans+=st.size();
            }
        }
        return ans;
    }
};