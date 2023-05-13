#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> m;

    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        if(m.empty() || val <= m.top()) {
            m.push(val);
        }
    }
    
    void pop() {
        if(m.top() == s.top()) {
            m.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};

int main() {
    cout << "This is a stack implementation using array\n";	
    MinStack* minstack = new MinStack();
    minstack->push(2);
    minstack->push(3);
    minstack->push(4);
	minstack->push(9);
	minstack->push(6);
	minstack->push(8);
	minstack->push(7);
	minstack->push(5);
    cout << "MinStack top : " << minstack->top() << endl;
	minstack->pop();
    minstack->push(1);
    cout << "minstack top : " << minstack->top() << endl;
    cout << "minstack top : " << minstack->top() << endl;
    cout << "getinMin : " << minstack->getMin() << endl;
    return 0;
}