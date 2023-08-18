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

    v
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode *ans=new ListNode(0);
        ListNode *curr=ans;
        
        
        while(left != NULL && right != NULL)
        {
            if(left->val <= right->val)
            {
                curr->next = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
            }
        
        curr = curr->next;
        
        }
        
        if(left != NULL)
        {
            curr->next = left;
            left = left->next;
        }
        
        if(right != NULL)
        {
            curr->next = right;
            right = right->next;
        }
       
        
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !(head->next) )
            return head;
        
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
      
        while(fast !=  NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;          
            fast = fast->next->next; 
            
        }   
        temp->next = NULL;           
        
        ListNode* left = sortList(head);    
        ListNode* right = sortList(slow);    
        
        return merge(left, right);
        

    }
};
