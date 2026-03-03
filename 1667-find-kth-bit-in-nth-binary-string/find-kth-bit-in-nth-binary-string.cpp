class Solution {
public:
    char findKthBit(int n, int k) {
        string s="";
        for(int i=0;i<n;i++){
            if(i==0){
                s.push_back('0');
            }
            else{
                string temp=s;
                s.push_back('1');
                for(int j=temp.size()-1;j>=0;j--){
                    if(temp[j]=='0'){
                        s.push_back('1');
                    }
                    else{
                        s.push_back('0');
                    }
                }
                //s+=temp;
            }
            //cout<<s<<" ";
        }
        return s[--k];
    }
};