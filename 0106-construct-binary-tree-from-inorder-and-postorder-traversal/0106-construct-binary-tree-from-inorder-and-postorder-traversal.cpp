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
void SearchMap(vector<int> in, unordered_map<int, int> &Inorder_Index)
{
    for (int i = 0; i < in.size(); i++)
    {
        Inorder_Index[in[i]] = i;
    }
}
public:
TreeNode* Inorder_PostorderBuild(vector<int>& postorder,int& i,int start,int end,unordered_map<int, int>& Inorder_Index){
    if(i<0 or start>end)return NULL;

    int x=postorder[i];
    TreeNode* root=new TreeNode(x);
    int position=Inorder_Index[x];
    i--;
    root->right=Inorder_PostorderBuild(postorder,i,position+1,end,Inorder_Index);
    root->left=Inorder_PostorderBuild(postorder,i,start,position-1,Inorder_Index);

    return root;

}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> Inorder_Index;
    SearchMap(inorder, Inorder_Index);
    int i = postorder.size()-1;
    int end = inorder.size() - 1;
    TreeNode *root = Inorder_PostorderBuild(postorder, i, 0, end, Inorder_Index);
    return root;
}
};