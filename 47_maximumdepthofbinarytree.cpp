class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int maxdepth =max(maxDepth(root->left),maxDepth(root->right));
        return maxdepth+1;
    }
};