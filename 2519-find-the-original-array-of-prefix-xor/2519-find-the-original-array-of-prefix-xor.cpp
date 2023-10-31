class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        int a=pref[0];
        for(int i=1;i<n;i++){
           int x=pref[i]^a;
            a=pref[i];
            pref[i]=x;
        }
        return pref;
    }
};