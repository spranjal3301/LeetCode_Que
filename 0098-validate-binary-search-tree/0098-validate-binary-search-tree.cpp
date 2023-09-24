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
public:
 bool isValidBST(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr) {
    // Base case: An empty tree is a valid BST.
    if (!root) return true;

    // Check if the current node's value is within the valid range.
    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
        return false;
    }

    // Recursively check the left and right subtrees with updated range.
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}
};