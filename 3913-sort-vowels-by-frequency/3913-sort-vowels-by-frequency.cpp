class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,int> firstPos;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                freq[ch]++;
                if(firstPos.find(ch) == firstPos.end()){
                    firstPos[ch] = i;
                }
            }
        }

        vector<pair<char,int>> v;
        for(auto &it : freq){
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end(), [&](pair<char,int> &a, pair<char,int> &b){
            if(a.second != b.second)
                return a.second > b.second;
            return firstPos[a.first] < firstPos[b.first];
        });

        string temp = "";
        for(auto &p : v){
            temp.append(p.second, p.first);
        }

        int idx = 0;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                s[i] = temp[idx++];
            }
        }

        return s;
    }
};