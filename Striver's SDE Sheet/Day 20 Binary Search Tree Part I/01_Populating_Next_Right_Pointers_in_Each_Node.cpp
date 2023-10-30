/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// T.C.= O(N) || S.C.= O(N) 
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* temp=q.front();
                q.pop();

                if(i!=n-1) temp->next=q.front(); // pointing the last element to the first if its the last element then the q.front will be NULL as the queue will be empty

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return root;      
        
    }
};

// T.C.= O(N) || S.C.= O(1) 
class Solution {
public:
    Node* connect(Node* root) {       

        Node* head=root;
        for(;root;root=root->left){
            for(auto curr=root;curr;curr=curr->next){
                if(curr->left){
                    curr->left->next=curr->right;
                    if(curr->next){
                        curr->right->next=curr->next->left;
                    }
                }
                else break;
            }
        }
        return head;
        
    }
};
