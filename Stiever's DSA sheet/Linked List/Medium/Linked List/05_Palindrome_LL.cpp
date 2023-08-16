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
    bool isPalindrome(ListNode* head) {
        ListNode* rev=NULL;
        ListNode* temp=head;
       
        while(temp!=NULL){
            ListNode* newNode = new ListNode(temp->val);
            // dbg(temp->val);
            newNode->next=rev;
            rev=newNode;
            // dbg(rev->val);
            temp=temp->next;
        }
        cout<<"rev : "; printList(rev);
        temp=head;
        cout<<"temp : ";printList(temp);
        while(temp!=NULL && rev!=NULL){
            if(temp->val!=rev->val){
                return false;
            }
            temp=temp->next;
            rev=rev->next;
        }

        return true;


    }
};
