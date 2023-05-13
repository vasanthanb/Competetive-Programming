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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) {
            return list2;
        }
        else if (list2 == NULL) {
            return list1;
        }
        if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
        }
    }
};

int main() {
    
}