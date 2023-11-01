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
    void Inorder(TreeNode* root,vector<int> &in){
        if(!root)return;

        Inorder(root->left,in);
        in.push_back(root->val);
        Inorder(root->right,in);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> in;
        vector<int> ans;
        int maxi=0;
        int cnt=0;
        Inorder(root,in);
        int var=in[0];
        int n=in.size();


        for(int i=0;i<n;i++){
            if(var==in[i]){
                cnt++;
            }
            else{
                var=in[i];
                cnt=1;
            }


            if(cnt>maxi){
                maxi=cnt;
                ans.clear();
                ans.push_back(in[i]);
            }
            else if(cnt==maxi){
               ans.push_back(in[i]); 
            }
        }
        return ans;
    }
};