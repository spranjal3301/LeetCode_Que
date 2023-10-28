class Solution {
public:
    int subsetXORSum(std::vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans |= num; // Calculate XOR of all elements directly
        }
        return ans * pow(2, nums.size() - 1); // Multiply by 2^(n-1) to account for all subsets
    }
};