class Stack {
public:
    queue<int> q;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int n = q.size();
        for (int i=0; i<n-1; i++){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        q.pop();
    }

    // Get the top element.
    int top() {
        int n = q.size();
        for (int i=0; i<n-1; i++){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        int res = q.front();
        q.pop();
        q.push(res);
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};