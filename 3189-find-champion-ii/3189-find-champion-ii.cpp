class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> v(n,0);
        // int m=edges.size();
        for(auto i:edges){
            v[i[1]]++;
        }
        int ans=0;
        int ck=0;
        for(int i=0;i<n;i++){

            if(v[i]==0){
                ck++;
                ans=i; 
            }
            if(ck>1)return -1;
        }
        return ans;
    }
};