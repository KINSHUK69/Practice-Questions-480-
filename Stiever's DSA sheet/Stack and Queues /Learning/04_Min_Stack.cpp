// T.C.= O(1) S.C.= O(2N)
class MinStack {
    stack<pair<int,int> >st;
public:

    MinStack() {
        
    }
    
    void push(int val) {
        int minimum;
        if(st.empty())minimum=val;
        else minimum=min(val,st.top().second);
        st.push({val,minimum});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
// T.C.= O(1) S.C.= O(1)
class MinStack {
    stack<long long>st;
    long long minimum;
public:

    MinStack() {
        
    }
    
    void push(int val) {
        long long v=val;
        
        if(st.empty()){
            minimum=val;
            st.push(val);
        }
        else if(minimum>val){
            st.push(2*v-minimum);
            minimum=val;
        }
        else 
            st.push(v);

    }
    
    void pop() {
        if(st.top()<minimum)
            minimum=2*minimum-st.top();
        st.pop();
    }
    
    int top() {
        if(minimum>st.top())return minimum;
        return st.top();
    }
    
    int getMin() {
        return minimum;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
