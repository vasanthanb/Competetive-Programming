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

    void pushfront(int val) {
        ListNode* newnode = new ListNode(val);
        newnode->next = head;
        head = newnode;
    }

    void pushafter(int key, int val) {
        ListNode* newnode = new ListNode(val);
        ListNode* temp = head;
        while (temp) {
            if (temp->val == key) {
                break;
            }
            else {
                temp = temp->next;
            }
        }
        newnode->next = temp->next;
        temp->next = newnode;
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

    void recursivetraversal(ListNode* head) {
        if(head == NULL) {
            return;
        }
        cout << head->val << " ";
        recursivetraversal(head->next);
    }

    void backtraversal(ListNode* head) { //recursion
        if(head == NULL) {
            return;
        }
        backtraversal(head->next);
        cout << head->val << " ";
    }

    void deleteatfront() {
        ListNode* temp = head;
        head = head->next;
    }

    void deletemiddle(int val) {
        ListNode* temp = head;
        ListNode* prev = head;
        while(temp){
            if(temp->val == val) {
                break;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        prev->next = temp->next;
    }

    void deleteatend() {
        ListNode* temp = head;
        while(temp->next->next) {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void deleteat(int i) {
        int pos = 0;
        ListNode* temp = head;
        ListNode* prev = head;
        while(temp) {
            if(pos == i) {
                break;
            }
            else {
                pos++;
                prev = temp;
                temp = temp->next;
            }
        }
        prev->next = temp->next;
    }

    bool search(int key) {    //iteration
        ListNode* temp = head;
        while(temp) {
            if(temp->val == key) {
    
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool search(ListNode* head, int key) {    //recursion
        if(head == NULL) {
            return false;
        }
        else if(head->val == key) {
            return true;
        }
        else {
            return search(head->next, key);
        }
    }

    int length() {    //iteration
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int length(ListNode* head) {    //recursion
        if(head == NULL) {
            return 0;
        }
        else {
            return 1 + length(head->next);
        }
    }

    void get(int n) {
        int i = 1;
        ListNode* temp = head;
        while (temp) {
            if (i == n) {
                break;
            }
            else {
                i++;
                temp = temp->next;
            }
        }
        cout << temp->val << endl;
    }

    void reverse() {     //iteration
        ListNode* current = head;
        ListNode* next = NULL;
        ListNode* previous = NULL;
        while(current) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
        traversal();
    }

    ListNode* reverseList(ListNode* head) { //recursion
        // if(head == NULL || head->next == NULL) {
        //     return head;
        // }
        // ListNode* result = reverseList(head->next);
        // head->next->next = head;
        // head->next = NULL;
        // return result;

        //using vector
        vector<int> elements;
        for(ListNode* temp = head; temp != NULL; temp = temp->next) {
            elements.push_back(temp->val);
        }
        for(ListNode* temp = head; temp != NULL; temp = temp->next) {
            temp->val = elements.back();
            elements.pop_back();
        }
        return head;
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
    // list.traversal();
    // list.pushfront(0);
    // list.pushafter(4, 6);
    // list.traversal();
    // list.pushback(7);
    // list.traversal();
    // list.deleteatfront();
    // list.deleteatend();
    // list.deletemiddle(6);
    // list.traversal();
    // cout << list.search(5) << endl;
    // list.traversal();
    // cout << list.length() << endl;
    // list.deleteat(1);
    // list.traversal();
    // list.get(3);
    // list.reverse();
    // list.backtraversal(list.head);
    // cout << endl;
    // list.recursivetraversal(list.head);
    // cout << endl;
    ListNode* head = list.reverseList(list.head);
    list.recursivetraversal(head);
    return 0;
}