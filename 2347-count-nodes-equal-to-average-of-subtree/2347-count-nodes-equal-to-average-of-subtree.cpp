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
private:
    // DFS to calculate the sum and count of nodes in each subtree
    pair<int, int> dfs(TreeNode* root, int& cnt) {
        if (!root) {
            return {0, 0}; // Return {sum, count}
        }

        auto left = dfs(root->left, cnt);
        auto right = dfs(root->right, cnt);

        int sum = left.first + right.first + root->val;
        int totalNodes = left.second + right.second + 1;

        int avg = sum / totalNodes;
        if (root->val == avg) {
            cnt++;
        }

        return {sum, totalNodes};
    }

public:
    // Calculate the number of subtrees where the average equals the root node value
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }
};
