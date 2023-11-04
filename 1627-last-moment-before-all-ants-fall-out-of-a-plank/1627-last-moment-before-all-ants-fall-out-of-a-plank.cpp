class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi=-1;
        for(auto i:left){
            maxi=max(i,maxi);
        }
        for(auto i:right){
            maxi=max(n-i,maxi);
        }
        return maxi;
    }
};