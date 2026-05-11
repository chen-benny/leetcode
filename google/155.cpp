// auxiliary min stack, T: O(1) all ops, S: O(n)

#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<int> stk;
    std::stack<int> minStk;

public:
    MinStack() = default;

    void push(int val) {
        stk.push(val);
        minStk.push(minStk.empty() ? val : std::min(val, minStk.top()));
    }

    void pop() {
        stk.pop();
        minStk.pop();
    }

    int top() { return stk.top(); }
    int getMin() { return minStk.top(); }
};
