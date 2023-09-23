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
    bool Path(TreeNode* root, int targetSum,int sum) {
        if(!root)return 0;
        sum+=root->val;
        bool left=Path(root->left,targetSum,sum);
        bool right=Path(root->right,targetSum,sum);

        if(targetSum==sum and !root->left and !root->right)return 1;
        if(left)return left;
        if(right)return right;

        return 0;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        bool ans=Path(root,targetSum,0);

        return ans;
    }
};