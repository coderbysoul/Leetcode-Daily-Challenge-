//https://leetcode.com/problems/merge-k-sorted-lists/description/

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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> temp;
        for(int i=0;i<lists.size();i++){
            ListNode* t= lists[i];
            if(t){
                while(t){
               temp.push_back(t->val);
                t=t->next;
            }
            }
            
          
        }
        sort(temp.begin(), temp.end());
        ListNode* ans=nullptr;
        ListNode*curr;
        for(int i=0;i<temp.size();i++){
            if(i==0){
               
                ans=new ListNode(temp[i]);
                curr=ans;
            }else{
               
                curr->next=new ListNode(temp[i]);
                curr=curr->next;
            }
           
        }


        return ans;
        
    }
};