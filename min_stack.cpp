class MinStack {
    stack<int> data;
    stack<int> min;
public:
    void push(int x) {
        if(data.empty())
        {
            data.push(x);
            min.push(x);
        }
        else{
            data.push(x);
        
            if(x<=min.top()){
                min.push(x);
            }
        }
    }

    void pop() {
        int x = data.top();
        data.pop();
        if(x==min.top())
        {
            min.pop();
        }
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
};