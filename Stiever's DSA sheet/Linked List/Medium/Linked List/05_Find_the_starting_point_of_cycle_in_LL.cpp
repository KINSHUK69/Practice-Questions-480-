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
    ListNode *detectCycle(ListNode *head) {
      LiseNode* slow=head;
      LiseNode* fast=head;
      bool flag=false;
      while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
          flag=true;
          break;
        }
      }
      if(!flag) return NULL;
      slow=head;
      while(head!=slow){
        head=head->next;
        slow=slow->next;
      }
      return slow;
    }
};
