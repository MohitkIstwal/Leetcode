class Solution {
public:

    bool helper(vector<vector<int>> &v, int m){
        for(auto vec: v){
                if(m<vec[1] || m-vec[0]<0){
                    return false;
                }
                m-=vec[0];
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int> &a, vector<int> &b){
            return a[1]-a[0]>b[1]-b[0];
        });
        int l=1,h=1e9,ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            cout<<m<<" ";
            if(helper(tasks,m)){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};