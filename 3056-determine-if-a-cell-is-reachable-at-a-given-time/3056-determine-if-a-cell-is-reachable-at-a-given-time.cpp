class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x=abs(fx-sx);
        int y=abs(fy-sy);
        if(x==y && x==0 && t==1)return false;

        
        return max(x,y)<=t;


    }
};