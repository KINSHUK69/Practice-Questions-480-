// push operation O(N)+O(N) method 
class MyQueue {
    stack<int>a;
    stack<int>b;
public:
    MyQueue() {
        
    }
    
    void push(int x) {        
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        a.push(x);
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
    }
    
    int pop() {
        int data=a.top();
        a.pop();
        return data;
        
    }
    
    int peek() {
        return a.top();
    }
    
    bool empty() {
        return a.empty();
    }
};
// push operation O(1) Amortized Method
class MyQueue {
    stack<int>a;
    stack<int>b;
public:
    MyQueue() {
        
    }
    
    void push(int x) {        
        a.push(x);
    }
    
    int pop() {
        if(b.empty()){
            while(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }
        int data=b.top();
        b.pop();
        return data;
        
    }
    
    int peek() {
        if(b.empty()){
            while(!a.empty()){
                b.push(a.top()),a.pop();
            }
        }
        return b.top();
    }
    
    bool empty() {
        return b.empty() and a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
