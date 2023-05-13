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
    
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ans = new ListNode();
    int sum, carry = 0;
    while(l1 || l2) {
        sum = l1->val + l2->val + carry;
        carry = sum / 10;
        ans->next = new ListNode(sum % 10);
    }
    if(l1 != NULL) {
        l1 = l1->next;
    }
    if(l2 != NULL) {
        l2 = l2->next;
    }
    if(carry == 1) {
        ans->next = new ListNode(1);
    }
    return ans->next;
}

int main() {
    string input1, input2;
    getline(cin, input1);
    getline(cin, input2);
    stringstream stream1(input1);
    vector<int> l1;
    int s1;
    while(stream1 >> s1) {
        l1.push_back(s1);
    }
    LinkedList list1;
    for(auto i : l1) {
        list1.pushback(i);
    }
    stringstream stream2(input2);
    vector<int> l2;
    int s2;
    while(stream2 >> s2) {
        l2.push_back(s2);
    }
    LinkedList list2;
    for(auto i : l2) {
        list2.pushback(i);
    }
    ListNode* l3 = addTwoNumbers(list1.head, list2.head);
    while(l3) {
        cout << l3->val << " ";
        l3 = l3->next;
    }
    cout << endl;
    return 0;
}