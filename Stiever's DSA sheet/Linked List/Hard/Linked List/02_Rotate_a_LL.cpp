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
// T.C. = O(n)+ O(n-(k%n))
class Solution {
public:

    int size(ListNode* head) {
        ListNode* dummy=head;
        int length=0;
        while(dummy!=NULL){
            length++;
            dummy=dummy->next;
        }
        return length;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr;
        ListNode* nex;

        int len=size(head);

        while(len>=k){
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev=curr;
            len-=k;
        }
        return dummy->next;

    }
};
