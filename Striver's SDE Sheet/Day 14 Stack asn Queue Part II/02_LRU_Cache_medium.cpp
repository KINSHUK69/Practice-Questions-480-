// Using DEQUEUE
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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
