class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int a=0,ans=0;
        for(int i=0;i<g.size();i++){
            while(a<s.size()){
                if(s[a]>=g[i]){
                    ans++; a++; break;
                }
                a++;
            }
        }
        return ans;
    }
};