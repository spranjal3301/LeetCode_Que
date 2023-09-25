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
TreeNode* solve(vector<int>& po,int mini,int maxi,int &i){
    if(i>=po.size())return NULL;

    if(po[i]<mini || po[i]>maxi)return NULL;
    TreeNode* root=new TreeNode(po[i]);
    i++;
    root->left=solve(po,mini,root->val,i);
    root->right=solve(po,root->val,maxi,i);
    return root;
}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,INT_MIN,INT_MAX,i);
    }
};