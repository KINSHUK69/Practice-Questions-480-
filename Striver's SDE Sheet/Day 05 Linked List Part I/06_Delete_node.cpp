/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev;
        while(node->next!=NULL){
            ListNode*  temp=node->next;
            swap(node->val,temp->val);
            prev=node;
            node=node->next;
        }
        prev->next=NULL;

    }
    void deleteNode(ListNode* node) {
       node->val = node->next->val;
       node->next = node->next->next;
    }
};
