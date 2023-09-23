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
    TreeNode* minValue(TreeNode* root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
    TreeNode* maxValue(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;

        if(root->val==key){
            // case1 0 Child
            if(!root->left and !root->right){
                delete root;
                return NULL;
            }

            // case2 1 Child
                if(root->left and !root->right){
                    TreeNode* temp=root->left;
                    delete root;
                    return temp;
                }
                else if(!root->left and root->right){
                    TreeNode* temp=root->right;
                    delete root;
                    return temp;
                }
            // case3 1 Child
                if(root->left and root->right){
                    int mini=minValue(root->right)->val;
                    root->val=mini;
                    root->right=deleteNode(root->right,mini);
                    return root;
                }

        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else{
            root->right=deleteNode(root->right,key);
            return root; 
        }
        return NULL;
    }
};