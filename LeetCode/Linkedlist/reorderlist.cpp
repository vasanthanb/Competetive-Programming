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

    void traversal() { //iteration
        ListNode* temp = head;
        while(temp != NULL) {
            cout << temp->val << " " ;
            temp = temp->next;
        }
        cout << endl;
    }

    void reorderList(ListNode* head) {
        //brute-force recursion
        // //base case i.e if the linked list has zero,one or two elments just return it
        // if(!head || !head->next || !head->next->next) return;
        
        // //Find the penultimate node i.e second last node of the linkedlist
        // ListNode* penultimate = head;
        // while (penultimate->next->next) penultimate = penultimate->next;
        
        // // Link the penultimate with the second element
        // penultimate->next->next = head->next;
        // head->next = penultimate->next;
        
        // //Again set the penultimate to the the last 
        // penultimate->next = NULL;
        
        // // Do the above steps rcursive
        // reorderList(head->next->next);

        
    }

};

int main() {
    LinkedList list;
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
    list.traversal();
    list.reorderList(list.head);
    list.traversal();
    return 0;
}