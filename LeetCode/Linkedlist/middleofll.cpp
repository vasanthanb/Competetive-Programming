#include<bits/stdc++.h>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() {
        this->val = 0;
        this->next = NULL;
    }

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }

    ListNode (int val, ListNode* next) {
        this->val = val;
        this->next = next;
    }
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() {
        this->head = NULL; 
    }

    LinkedList(int val) {
        this->head->val = val;
    }

    void pushback(int val) {
        ListNode* newnode = new ListNode(val);
        if(this->head == NULL) {
            this->head = newnode;
        }
        else {
            ListNode* temp = head;
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    string input;
    getline(cin, input);
    stringstream stream(input);
    vector<int> ll;
    int e;
    while(stream >> e) {
        ll.push_back(e);
    }
    LinkedList list;
    for(auto i : ll) {
        list.pushback(i);
    }
    ListNode* mid = list.middleNode(list.head);
    cout << mid->val << endl;
}