// Brute Force : Using DEQUEUE
// TLE 
// test case passed 20/22
class LRUCache {
public:
    int max=0; 
    list<int>q;
    unordered_map<int,int>mp;
    LRUCache(int capacity) {
        max=capacity;
    }
    
    int get(int key)  // O(N)
    {
        if(mp.find(key)!=mp.end()){
            q.remove(key); // O(n)
            q.push_back(key);// O(1)
            return mp[key];
        }        
        return -1;
    }
    
    void put(int key, int value)  // O(N)
    {
        if(mp.find(key)!=mp.end()){
            q.remove(key);
            q.push_back(key);
            mp[key]=value;
        }
        else{
            if(q.size()==max){
                int i=q.front();
                mp.erase(i);
                q.pop_front();
            }
            q.push_back(key);
            mp[key]=value;
        }
    }
};

// Optimal : Using DoublyLinkedList

class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node* next;
            node* prev;

            node(int key,int val){
                this->key=key;
                this->val=val;
            }
    };
    int max=0; 
    node* tail = new node(-1,-1);
    node* head = new node(-1,-1);

    unordered_map<int,node*>mp;

    LRUCache(int capacity) {
        max=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(node* newNode){
        node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(node * del){
        node* delprev=del->prev;
        node* delnext=del->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        if(mp.find(key)!= mp.end()){
            node* temp = mp[key];
            int ans = temp->val;
            mp.erase(key);
            deleteNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return ans;
        }        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        
        if(mp.size() == max){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


