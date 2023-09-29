class MinStack {
    stack<pair<int,int>> st;  // { val,min_Element }
public:

    
    MinStack() {
        
    }
    
    void push(int val)   // O(1)
    {
        int minEle;
        if(st.empty()) minEle = val;
        else minEle = min(val,st.top().second );

        st.push(val,minEle);
    }
    
    void pop() // O(1)
    {
            st.pop();
    }
    
    int top() // O(1)
    {      
       st.top().first;
    }
    
    int getMin() // O(1)
    {
        st.top().second;
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
