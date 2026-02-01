class RideSharingSystem {
public:

    // okay so logic is as follows
    // we will create two queues to store the riders and drivers
    // then for active riders we will create a set to cancel riders and later we will check while assigning it to match order function

    queue<int> rider,driver;
    unordered_set<int> activerider;

    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        activerider.insert(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!rider.empty() && activerider.count(rider.front())==0){
            rider.pop();
        }
        vector<int> v={-1,-1};
        if(!rider.empty() && !driver.empty()){
            v[0]=driver.front(); driver.pop();
            v[1]=rider.front(); rider.pop();
        }
        return v;
    }
    
    void cancelRider(int riderId) {
        if(activerider.count(riderId)){
            activerider.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */