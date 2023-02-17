class Solution {
    private:
    void inOrder(TreeNode* root, vector<int>& res){
        if(root==NULL) return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int>res;
        int diff;
        int minimum=INT_MAX;
       
        inOrder(root,res);
        for(int i=1;i<res.size();i++)
        {
         diff=res[i]-res[i-1];
         if(diff<minimum)
         minimum=diff;
        }
        return minimum;
    }
};