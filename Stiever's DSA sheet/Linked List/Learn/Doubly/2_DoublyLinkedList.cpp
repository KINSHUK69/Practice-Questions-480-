#include<iostream>
using namespace std;

class Node
{
    public:
        int data;        
        Node *next;
        Node *prev;
        Node(){
            data=0;
            next=NULL;
            prev=NULL;
        }

        Node(int data){
            this->data=data;
            this->next=NULL;
            this->prev=NULL;
        }

};


class List{
    Node *head;
    
    int size;
    
    public:
        List(){
            head=NULL;
        }
        void insertNodeFirst(int);
        void insertNodeLast(int);
        void insertNodeAt(int,int);
        void deleteNodeLast();
        void deleteNodeAt(int);
        void deleteNodeFirst();
        
        
        void printList();

};

void List::insertNodeFirst(int data){
    Node *temp=new Node(data);
    temp->next=head;
    temp->prev=NULL;

    if(head!=NULL){
        head->prev=temp;
    }
    head=temp;
          
}

void List::insertNodeLast(int data){
    Node *newNode=new Node(data);
    if(head==NULL){
        head=newNode;        
        return;
    }
    Node *last=head;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newNode;
    newNode->prev=last; 
       
}

void List::insertNodeAt(int data,int index){
    if(index==0){
        insertNodeFirst(data);
        return;
    }
    Node *temp=head;
    for(int i=1;i<index;i++){
        temp=temp->next;
    }
    Node *t=new Node(data);
    t->next=temp->next;
    t->prev=temp->prev;
    temp->next=t;        
    
}

void List::deleteNodeFirst(){
    if(head==NULL){
        cout<<"Empty list\n";
        return;
    }
    Node *temp=head;
    head=head->next;
    head->prev=NULL;
    delete(temp);
    
}

void List::deleteNodeLast(){
    if(head==NULL){
        cout<<"Empty list\n";
        return;
    }
    Node *end=head;
    Node *prev;
    while(end->next!=NULL){
        prev=end;
        end=end->next;
    }
    prev->next=NULL;
    delete(end);
    
}
void List::deleteNodeAt(int index){
    if(head==NULL){
        cout<<"Empty list\n";
        return;
    }

    Node *prev_ele = head;        

    if(index==0){
        deleteNodeFirst();
        return;
    }
    // finding previous node
    for(int i=1;i<index-1 && prev_ele!= NULL;i++){
        prev_ele=prev_ele->next;
    }
    // cout<<" prev : "<< prev->data;

    if(prev_ele== NULL ) {
        cout<<"invalid size"; 
        return;
    }
    if(prev_ele->next== NULL ) {
        cout<<"invalid size"; 
        return;
    }

    Node *temp2=prev_ele->next->next;
    temp2->prev->prev=prev_ele;
    delete(prev_ele->next);
    prev_ele->next=temp2;
    
    
}


void List::printList(){
    Node *temp=head;
    if(head==NULL){
        cout<<"empty list\n";
        return;
    }
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<"\n";
}

int main(){
    List li;
    int size=0;
    cout<< "Inserting at the end :"<<"\n";
    li.insertNodeLast(1);
    li.insertNodeLast(2);
    li.insertNodeLast(3);
    li.insertNodeLast(4);    
    li.insertNodeLast(5);    
    li.insertNodeLast(6);    
    li.insertNodeLast(7);    
    li.printList();
    cout<< "Inserting at the begining :"<<"\n";
    li.insertNodeFirst(0);
    li.printList();
    cout<< "Inserting at a given index (0 at third index):"<<"\n";
    li.insertNodeAt(0,3);
    li.printList();
    cout<<"Deteting first : \n";
    li.deleteNodeFirst();
    li.printList();
    cout<<"Deteting Last : \n";
    li.deleteNodeLast();
    li.printList();
    cout<<"Deteting the given index : (deleting element at second index) \n";
    li.deleteNodeAt(3);
    li.printList();

    return 0;
}

