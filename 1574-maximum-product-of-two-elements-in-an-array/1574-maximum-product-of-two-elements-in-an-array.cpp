class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fl=-1;
        int sl=-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>fl){
                sl=fl;
                fl=nums[i];
            }
            else if(nums[i]>sl)sl=nums[i];
        }
        int a=sl-1;
        int b=fl-1;
        return a*b;
    }
};