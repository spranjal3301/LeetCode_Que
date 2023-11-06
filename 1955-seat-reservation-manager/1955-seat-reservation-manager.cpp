class SeatManager {
    set<int> urseat;
    unordered_map<int,bool> seat;
    int i;
    int size;
public:
    SeatManager(int n) {
        i=1;
        size=n;
    }
    
    int reserve() {
        if(!urseat.empty()){
            set<int>::iterator it = urseat.begin();
            int firstElement = *it;
             urseat.erase(urseat.begin());
            return firstElement;
        }
        seat[i++]=true;
        return i-1;
        
        
    }
    
    void unreserve(int seatNumber) {
        urseat.insert(seatNumber);
        seat[seatNumber]=false;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */