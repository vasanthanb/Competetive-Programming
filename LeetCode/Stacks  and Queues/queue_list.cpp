#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
        int value;
        Node* next;

		Node () {
			this->value = 0;
			this->next = NULL;
		}

        Node (int value) {
            this->value = value;
            this->next = NULL;
        }
};

class Queue {
    public:
        Node* front;
        Node* rear;
		int size;

        Queue() {
            this->front = NULL;
            this->rear = NULL;
        }

        void Enqueue(int x);
        int Dequeue();
        int QueueTop();
		int Queuesize();
		bool QueueIsEmpty();
		void Queueprint();
};

void Queue::Enqueue (int x) {
    Node* node = new Node(x);
    if (this->front == NULL) {
        this->front = node;
        this->rear = this->front;
    }
    else {
        this->rear->next = node;
        this->rear = node;
	    this->size++;
    }
}

int Queue::Dequeue () {
    int front = this->front->value;
    this->front = this->front->next;
	this->size--;
    return front;
}

int Queue::QueueTop () {
    return this->front->value;
}

int Queue::Queuesize () {
	return this->size;
}

bool Queue::QueueIsEmpty () {
	return (front == NULL);
}

void Queue::Queueprint () {
	Node* curr = new Node();
	curr = front;
	while (curr)
	{
		cout << curr->value << " ";
		curr = curr->next;
	}

}

int main() {
    cout << "This is a Queue implementation using linkedlist\n";	
    Queue* queue = new Queue();
    queue->Enqueue(2);
    queue->Enqueue(3);
    queue->Enqueue(4);
	queue->Enqueue(9);
	queue->Enqueue(6);
	queue->Enqueue(8);
	queue->Enqueue(7);
	queue->Enqueue(5);
    cout << "Queue top : " << queue->QueueTop() << endl;
    cout << "Dequeue : " << queue->Dequeue() << endl;
    queue->Enqueue(1);
    cout << "Queue top : " << queue->QueueTop() << endl;
	cout << "Queue size : " << queue->Queuesize() << endl;
	queue->Queueprint();
	cout << endl;
    return 0;
}