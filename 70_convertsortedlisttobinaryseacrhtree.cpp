//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  TreeNode* sortedListToBST(ListNode* head, ListNode *end=NULL) 
{
    if (head==end) return NULL;
    ListNode *fast = head, *slow = head;
    while (fast!=end && fast->next!=end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *cur = new TreeNode;
    cur->val = slow->val;
    cur->left = sortedListToBST(head, slow);
    cur->right = sortedListToBST(slow->next, end);
    return cur;
}
};