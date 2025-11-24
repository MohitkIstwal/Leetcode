class Solution {
public:

    void helper(string &s,long long &num,int sign,int &i){
        if(s[i]<'0' || s[i]>'9'){
            return;
        }
        if(i==s.size()){
            return;
        }
        int digit=s[i]-'0';
        num=abs(num);
        num*=10;
        num+=digit;
        num*=sign;
        if(num>=INT_MAX){
            num=INT_MAX;
            return;
        }
        if(num<INT_MIN){
            num=INT_MIN;
            return;
        }
        //cout<<num<<" ";
        helper(s,num,sign,++i);
    }

    int myAtoi(string s) {
        if(s.empty()){
            return 0;
        }
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        long long num=0;
        helper(s,num,sign,i);
        return (int)num;
    }
};