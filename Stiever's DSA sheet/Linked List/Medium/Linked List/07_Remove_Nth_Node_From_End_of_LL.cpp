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
    
    void printList(ListNode* head){
        ListNode* temp=head;
        if(head==NULL){
            cout<<"empty list\n";
            return;
        }
        while(temp->next!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<temp->val<<"\n";
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return head;
        ListNode* prev=head;
        ListNode* curr=head;
        for(int i=0;i<n;i++){
            prev=prev->next;
        }
        // cout<<prev->val;
        // printList(head);
        if(prev==NULL)return head->next;
        
        while(prev->next){
            prev=prev->next;
            curr=curr->next;
        }

        ListNode* temp=curr->next;
        curr->next=curr->next->next;
        // printList(head);
        delete(temp);


        return head;
        
    }
};
