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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> q;
    
    vector<vector<int>>ans;
    if(root==NULL)
    return vector<vector<int>>() ;
    else
    {
    q.push_back(root);
      vector<int> v1;
    v1.push_back(root->val);
    ans.push_back(v1);
    TreeNode* temp;
   
   
    int l = 1;
                
    while (!q.empty()) {
        int n = q.size();
       vector<int>v;
       
        
        for (int i = 0; i < n; i++) {
 
            // popping mechanism
            if (l % 2 == 0) {
                temp = q.back();
                q.pop_back();
            }
            else {
                temp = q.front();
                q.pop_front();
            }
             
 
            // pushing mechanism
            if (l % 2 != 0) {
 
                if (temp->right) {
                    q.push_back(temp->right);
                    v.push_back(temp->right->val);
                }
                if (temp->left) {
                    q.push_back(temp->left);
                    v.push_back(temp->left->val);
                }
                 
            }
            else if (l % 2 == 0) {
 
                if (temp->left) {
                    q.push_front(temp->left);
                    v.push_back(temp->left->val);
                }
                if (temp->right) {
                    q.push_front(temp->right);
                    v.push_back(temp->right->val);
                }
                 
            }
           
        }
        if(!v.empty())
         ans.push_back(v);
        
        l++; 
    }
    }
    return ans;
   
}
    
};