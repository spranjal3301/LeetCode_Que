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
    void RightView(TreeNode *root ,vector<int> & ans,int level){
    if(!root)return;
    if(level==ans.size())
    ans.push_back(root->val);
    
    RightView(root->right,ans,level+1);
    RightView(root->left,ans,level+1);
}
public:
    vector<int> rightSideView(TreeNode* root) {
     if(!root)return {};
     vector<int> ans;
     RightView(root,ans,0);
     return ans;
   
    }
};