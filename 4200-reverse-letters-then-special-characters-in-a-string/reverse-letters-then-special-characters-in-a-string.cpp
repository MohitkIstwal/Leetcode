class Solution {
public:
    string reverseByType(string s) {
        string s1="",s2="";
        for(auto ch: s){
            if(isalpha(ch)){
                s1+=ch;
            }
            else{
                s2+=ch;
            }
        }
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int ind1=0,ind2=0;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                s[i]=s1[ind1];
                ind1++;
            }
            else{
                s[i]=s2[ind2];
                ind2++;
            }
        }
        return s;
    }
};