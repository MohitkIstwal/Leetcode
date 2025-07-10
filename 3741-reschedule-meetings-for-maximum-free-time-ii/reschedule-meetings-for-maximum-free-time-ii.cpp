class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<int>freetime;
        for(int i = 0;i<n;i++){
            if(i == 0){
                freetime.push_back(start[i] - 0);
            }else{
                freetime.push_back(start[i]-end[i-1]);
            }
        }
        freetime.push_back(eventTime - end[n-1]);
        
        multiset<int>st;
        for(int i = 0;i<freetime.size();i++){
            st.insert(freetime[i]);
        }
        int maxi = 0;
        for(int i = 0;i<n;i++){
            int duration = end[i] - start[i];
            int left = freetime[i],right = freetime[i+1];
            maxi = max(maxi,right+left);
            st.erase(st.find(left));
            st.erase(st.find(right));
            auto ind = st.lower_bound(duration);
            if(ind!=st.end()){
                maxi = max(maxi,right+left+duration);
            }
            st.insert(left);
            st.insert(right);
        }
        return maxi;
    }
};