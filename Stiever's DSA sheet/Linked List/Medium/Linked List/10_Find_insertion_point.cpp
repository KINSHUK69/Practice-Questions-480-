/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Brute Force  T.C. = O(m*n) , S.C. = O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        while(l2!=NULL){
            ListNode* temp=l1;
            while(temp!=NULL){
                if(temp==l2)return l2;
                temp=temp->next;
            }
            l2=l2->next;
        }
        return NULL;
    }
};

// Better solution  T.C. = O(m+n) , S.C. = O(n) 
class Solution {
public:
    
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
       unordered_set<ListNode *>st;
       while(l1!=NULL){
           st.insert(l1);
           l1=l1->next;
       }
       while(l2!=NULL){
           if(st.find(l2)!=st.end())return l2;
           l2=l2->next;
       }
       return NULL;
    }
};

// Best Solution   T.C. = O(2*max(m,n)) , S.C. = O(1)
class Solution {
public:
    
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
       ListNode* d1=l1;
       ListNode* d2=l2;
       while(d1!=d2){
           d1 = d1==NULL ? l2:d1->next;
           d2 = d2==NULL ? l1:d2->next;
       }
       return d1;
    }
};
