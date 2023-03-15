//https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

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
    bool isCompleteTree(TreeNode* root) {
        if(root->left==NULL and root->right==NULL){
            return true;
        }
        int flag=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f->left!=NULL and f->right!=NULL){
                if(flag==1){
                    return false;
                }
                q.push(f->left);
                q.push(f->right);
            }
            else if(f->left==NULL and f->right!=NULL){
                return false;
            }
            else if(f->left==NULL and f->right==NULL){
                flag=1;
            }
            else{
                if(flag==1){
                    return false;
                }
                q.push(f->left);
                flag=1;
            }
        }
        return true;
    }
};