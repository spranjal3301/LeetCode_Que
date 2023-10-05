class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int k=n/3;

        int count=1;
        if(count>k && (n==1 or nums[0]!=nums[1]))ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1])count=0;
            count++;
            if(count>k){
                ans.push_back(nums[i]);
                count=0;
                while( i<n-1 && nums[i]==nums[i+1]){     
                    i++;
                }
            
        
            }
        }
        return ans;
    }
};