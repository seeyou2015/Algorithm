//Use one more stack to store the mins
class MinStack {
    stack<int> stk;
    stack<int> min;
public:
    
    void push(int x) {
        stk.push(x);
        if(min.empty())
        {
            min.push(x);
        }
        else
        {
            if(x <= min.top())
                min.push(x);
        }
    }

    void pop() {
        if(stk.top() == min.top())
        {
            stk.pop();
            min.pop();
        }
        else
        {
            stk.pop();
        }
        
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min.top();
    }
};
