/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int mod=1e9+7;
public:
  void solve(TreeNode* root, int targetSum, vector<int>& path, int& count, unordered_map<int, int>& prefixSumCount, int currentSum = 0) {
    if (!root) return;
    currentSum += root->val;
    currentSum=currentSum%mod;
    // Check if there is a valid path ending at this node
    if (prefixSumCount.find(currentSum - targetSum) != prefixSumCount.end()) {
        count += prefixSumCount[currentSum - targetSum];
    }
    // Update the prefix sum count map
    prefixSumCount[currentSum]++;
    // Recurse on left and right subtrees
    solve(root->left, targetSum, path, count, prefixSumCount, currentSum);
    solve(root->right, targetSum, path, count, prefixSumCount, currentSum);
    // Restore the prefix sum count map for backtracking
    prefixSumCount[currentSum]--;
}

int pathSum(TreeNode* root, int targetSum) {
    vector<int> path;
    int count = 0;
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1; // Initialize with a prefix sum of 0
    solve(root, targetSum, path, count, prefixSumCount);
    return count;
}
};