class StockSpanner {
public:

    stack<pair<int,int>> st;

    StockSpanner() {
        while(!st.empty()){
            st.pop();
        }
    }
    
    int next(int x) {
        int a=1;
        while(!st.empty() && st.top().first<=x){
            a+=st.top().second; st.pop();
        }
        st.push({x,a});
        return a;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */