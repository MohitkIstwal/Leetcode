class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        for(int i=1;i<num.size()-1;i++){
            if(num[i]==num[i+1] && num[i-1]==num[i]){
                string temp="";
                temp.push_back(num[i]);
                temp.push_back(num[i]);
                temp.push_back(num[i]);
                if(temp>ans){
                    ans=temp;
                }
            }
        }
        return ans;
    }
};