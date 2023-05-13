#include<bits/stdc++.h>

using namespace std;

class Stack {
public:
    vector<int> stack;
    
    Stack() {
    
    }
    
    void push(int val) {
        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    // int getMin() {
    //     int Min = INT_MIN;
    //     for(int i = 0; i < stack.size() ; i++) {
    //         Min = min(Min, stack[i]);
    //     }
    //     return Min;
    // }
};

int main() {
    cout << "This is a stack implementation using array\n";	
    Stack* stack = new Stack();
    stack->push(2);
    stack->push(3);
    stack->push(4);
	stack->push(9);
	stack->push(6);
	stack->push(8);
	stack->push(7);
	stack->push(5);
    cout << "Stack top : " << stack->top() << endl;
    stack->push(1);
    cout << "stack top : " << stack->top() << endl;
	stack->pop();
    cout << endl;
    return 0;
}