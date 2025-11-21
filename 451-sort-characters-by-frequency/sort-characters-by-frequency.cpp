class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> v;
        map<char,int> mp;
        for(auto it: s){
            mp[it]++;
        }
        for(auto it: mp){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(), [](auto &a, auto &b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second>b.second;
        });
        string ans="";
        for(auto it: v){
            for(int i=0;i<it.second;i++){
                ans+=it.first;
            }
        }
        return ans;
    }
};