#include<iostream>
using namespace std;


#define dbg(x) cout<<#x<<" = "<<x<<endl

class Node
{
    public:
        int data;        
        Node *next;
        Node(){
            data=0;
            next=NULL;
        }

        Node(int data){
            this->data=data;
            this->next=NULL;
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
    head=temp;
          
}

void List::insertNodeLast(int data){
    Node *newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode; 
       
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
    // dbg(temp->data);
    Node *t=new Node(data);
    t->next=temp->next;
    temp->next=t;        
    
}

void List::deleteNodeFirst(){
    if(head==NULL){
        cout<<"Empty list\n";
        return;
    }
    Node *temp=head;
    head=head->next;
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

    Node *temp = head;        

    if(index==0){
        deleteNodeFirst();
        return;
    }
    // finding previous node
    for(int i=1;i<index-1 && temp!= NULL;i++){
        temp=temp->next;
    }
    // cout<<" prev : "<< prev->data;

    if(temp== NULL ) {
        cout<<"invalid size"; 
        return;
    }
    if(temp->next== NULL ) {
        cout<<"invalid size"; 
        return;
    }

    Node *temp2=temp->next->next;
    delete(temp->next);
    temp->next=temp2;
    
    
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
    cout<< "Inserting at a given index ( 0 at third index ) :"<<"\n";
    li.insertNodeAt(0,3);
    li.printList();
    cout<<"Deteting first : \n";
    li.deleteNodeFirst();
    li.printList();
    cout<<"Deteting Last : \n";
    li.deleteNodeLast();
    li.printList();
    cout<<"Deteting the given index ( element at second index ): \n";
    li.deleteNodeAt(3);
    li.printList();

    return 0;
}

