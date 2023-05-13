#include <bits/stdc++.h>
using namespace std;

class Node {
public: 
    int value;
    Node* next;

    Node() {
        this->value = NULL;
        this->next = NULL;
    }

    Node(int value) {
        this->value = value;
        this->next = NULL;
    }

    Node(int value, Node* next) {
        this->value = value;
        this->next = next;
    }
};

class Stack {
public:
    Node* top;
    int size;

    Stack() {
        this->top = NULL;
    }

    void StackPush(int x);
    int StackPop();
    int StackTop();
    int Stacksize();
    bool StackIsEmpty();
    void Stackprint();
};

void Stack::StackPush(int x) {
    Node* node = new Node(x);
    node->next = this->top;
    this->top = node;
	this->size++;
}

int Stack::StackPop() {
    int top = this->top->value;
    this->top = this->top->next;
	this->size--;
    return top;
}

int Stack::StackTop() {
    return this->top->value;
}

int Stack::Stacksize() {
	return this->size;
}

bool Stack::StackIsEmpty() {
	return (top == NULL);
}

void Stack::Stackprint() {
	Node* curr = new Node();
	curr = top;
	while(curr) {
		cout << curr->value << " ";
		curr = curr->next;
	}
}

int main() {
    cout << "This is a stack implementation using linkedlist\n";	
    Stack* stack = new Stack();
    stack->StackPush(2);
    stack->StackPush(3);
    stack->StackPush(4);
	stack->StackPush(9);
	stack->StackPush(6);
	stack->StackPush(8);
	stack->StackPush(7);
	stack->StackPush(5);
    cout << "Stack top : " << stack->StackTop() << endl;
    cout << "stack pop : " << stack->StackPop() << endl;
    stack->StackPush(1);
    cout << "stack top : " << stack->StackTop() << endl;
	cout << "Stack size : " << stack->Stacksize() << endl;
	stack->Stackprint();
	cout << endl;
    return 0;
}