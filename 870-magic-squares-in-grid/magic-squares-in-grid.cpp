class Solution {
public:

    bool helper(vector<vector<int>> &v,int row,int col,int n,int m){
        int a=row+2,b=col+2;
        if(a>n-1 || b>m-1){
            return false;
        }
        int sum=0;
        set<int> st;
        for(int i=row;i<=a;i++){
            sum=0;
            for(int j=col;j<=b;j++){
                if(v[i][j]>9 || v[i][j]==0){
                    return false;
                }
                sum+=v[i][j];
            }
            st.insert(sum);
        }
        if(st.size()>1){
            return false;
        }
        for(int i=col;i<=b;i++){
            sum=0;
            for(int j=row;j<=a;j++){
                if(v[j][i]>9 || v[j][i]==0){
                    return false;
                }
                sum+=v[j][i];
            }
            st.insert(sum);
        }
        if(st.size()>1){
            return false;
        }
        int i=row,j=col;
        int diagsum=v[i][j]+v[i+1][j+1]+v[i+2][j+2];
        st.insert(diagsum);
        int diagsum2=v[i][j+2]+v[i+1][j+1]+v[i+2][j];
        st.insert(diagsum2);
        if(st.size()>1){
            return false;
        }
        set<int> unique;
        for(int i=row;i<=a;i++){
            for(int j=col;j<=b;j++){
                if(v[i][j]<10 && v[i][j]>=1){
                    unique.insert(v[i][j]);
                }
            }
        }
        if(unique.size()!=9){
            return false;
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        if(n<3 || m<3){
            return 0;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool isthere=helper(v,i,j,n,m);
                if(isthere){
                    ans++;
                }
            }
        }
        return ans;
    }
};