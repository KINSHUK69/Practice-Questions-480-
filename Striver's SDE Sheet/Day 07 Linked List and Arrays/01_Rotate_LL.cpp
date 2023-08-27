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
 #define dbg(x) cout<<#x<<" = "<<x<<endl
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // T.L.E.
        // if(head==NULL || head->next==NULL ||k==0)return head;
        // ListNode* temp=head;        
        
        // while(k--){    

        //     ListNode* secondLast=head;

        //     while(secondLast->next->next!=NULL){
        //         secondLast=secondLast->next;
        //     } 

        //     ListNode* start=secondLast->next;              
        //     secondLast->next=NULL;
        //     start->next=head;
        //     head=start;            
        // }
        // return head;


        // convert it into a circular LL
        // then iterate a node till [k % size]  i.e. the last element of the rotated LL      
        // head = founded node
        // change the founded node ->next = NULL ;

        if(head==NULL || head->next==NULL || k==0) return head;

        int size=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            size++;
        }
        k=k%size;
        // cout<<k;
        temp->next=head;
        int end=size-k;
        while(end--){
            temp=temp->next;
        }
        // cout<<endl<<temp->val;
        head=temp->next;
        temp->next=NULL;

        return head;

    }
};
