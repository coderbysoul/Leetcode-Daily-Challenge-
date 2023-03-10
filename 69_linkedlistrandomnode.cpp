//https://leetcode.com/problems/linked-list-random-node/description/

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
    int len=0;    // initialize length
    ListNode *HeadNode;
public:
    Solution(ListNode* head) {
        HeadNode=head;
        ListNode *temp=HeadNode;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
    }
    
    int getRandom() {
        int random_index=rand()%len; // get random index 
        ListNode *temp=HeadNode;
        for(int i=0;i<random_index;i++){
            temp=temp->next;
        }
        return temp->val;
    }
}; 

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */