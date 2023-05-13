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

    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    LinkedList list;
    list.pushback(1);
    list.pushback(2);
    list.pushback(3);
    list.pushback(4);
    list.pushback(5);
}