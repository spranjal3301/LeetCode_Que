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
void inorder(TreeNode *root,vector<int>& in)
{
    if (root == NULL)
        return;
    TreeNode *current, *pre;

    current = root;
    while (current != NULL)
    {

        if (current->left == NULL)
        {
            in.push_back(current->val);
            current = current->right;
        }
        else                         
        {

            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                in.push_back(current->val);
                current = current->right;
            }
        }
    }
}
TreeNode* BulidBSTInorder(vector<int> tree,int start,int end){
    if(start>end){
        return NULL;
    }    
    int mid=(start+end)/2;
    TreeNode* root=new TreeNode(tree[mid]);
    root->left=BulidBSTInorder(tree,start,mid-1);
    root->right=BulidBSTInorder(tree,mid+1,end);
     
    return root;
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> tree;
        inorder(root,tree);
        
        return BulidBSTInorder(tree,0,tree.size()-1);;
    }
};