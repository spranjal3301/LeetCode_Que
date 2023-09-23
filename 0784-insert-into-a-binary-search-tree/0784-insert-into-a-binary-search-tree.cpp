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
    TreeNode* insertIntoBST(TreeNode* &root, int val) {
        if(!root){
            root=new TreeNode(val);
            return root;
        }

        TreeNode* temp;
        if(root->val>val){
            temp=insertIntoBST(root->left,val);
        }
        else{
            temp=insertIntoBST(root->right,val);
        }
        return root;
    }
};