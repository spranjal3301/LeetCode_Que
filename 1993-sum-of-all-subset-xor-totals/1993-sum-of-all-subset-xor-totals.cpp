class Solution {
    void solve(vector<int>& nums,vector<int>& subset,int i,int &ans){
        if(i>=nums.size()){
            int x=0;
            for(auto s:subset){
                x^=s;
            }
            ans+=x;
            return;
        }

        subset.push_back(nums[i]);
        solve(nums,subset,i+1,ans);
        subset.pop_back();

        solve(nums,subset,i+1,ans);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        int i=0;
        vector<int> subset;
        solve(nums,subset,i,ans);
        return ans;
    }
};