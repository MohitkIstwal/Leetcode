class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end(),greater<>());
        int ans=0;
        for(int i=0;i<capacity.size();i++){
            sum-=capacity[i];
            ans++;
            if(sum<=0){
                break;
            }
        }
        return ans;
    }
};