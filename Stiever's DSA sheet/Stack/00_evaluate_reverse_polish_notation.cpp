/*
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto &it:tokens){            
            if(it=="+" ||it=="-" ||it=="*" ||it=="/" ){
                long a=s.top(); s.pop();
                long b=s.top(); s.pop();
                if(it=="+") s.push(b+a);                
                if(it=="-")s.push(b-a); 
                if(it=="*")s.push(b*a);
                if(it=="/")s.push(b/a); 
            }
            
            else s.push(stoi(it));
        }
        return s.top();
    }
};
