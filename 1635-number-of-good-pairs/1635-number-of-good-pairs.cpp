class Solution {
public:
     int numIdenticalPairs(vector<int>& nums) {
        vector<int> freq(101, 0); // Store frequency of each number from 0 to 100
        int ans = 0;

        // Count the frequency of each number in nums
        for (int num : nums) {
            freq[num]++;
        }

        // Calculate the count of identical pairs for each number
        for (int f : freq) {
            if (f >= 2) {
                ans += (f * (f - 1)) / 2; // Combination formula C(f, 2) = (f * (f - 1)) / 2
            }
        }

        return ans;
    }
};