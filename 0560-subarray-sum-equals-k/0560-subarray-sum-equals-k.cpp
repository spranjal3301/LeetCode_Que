class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int res=0;
        unordered_map<int,int> ps;
        ps[0]=1;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(ps[sum-k]){
                res+=ps[sum-k];
            }
            ps[sum]++;
            // if(sum==k)res++;
        }

        return res;
    }
};