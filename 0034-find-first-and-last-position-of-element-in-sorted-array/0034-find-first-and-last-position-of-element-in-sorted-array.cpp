class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int sp = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int ep = lower_bound(nums.begin(), nums.end(), target+1) - nums.begin() - 1;
        if(sp < nums.size() && nums[sp] == target){
            return {sp, ep};
        }
        return {-1, -1};
    }
    
};