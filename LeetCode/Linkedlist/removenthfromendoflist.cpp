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

    // ListNode* removeNthFromEnd(ListNode* head, int n) { //brute force n^2 times
    //     int len = 0;
    //     ListNode* temp = head;
    //     while(temp) {
    //         len++;
    //         temp = temp->next;
    //     }
    //     int N = len - (n - 1);
    //     int count = 0;
    //     ListNode* prev = NULL;
    //     ListNode* curr = head;
    //     while(curr) {
    //         count++;
    //         if(N == count) {
    //             prev->next = curr ->next;
    //             break;
    //         }
    //         prev = curr;
    //         curr = curr->next;
    //     }
    //     return head;
    // }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if(fast == NULL) {
            return head->next;
        }
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
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
    int n;
    cin >> n;
    ListNode* ele = list.removeNthFromEnd(list.head, n);
    while(ele) {
        cout << ele->val << " ";
        ele = ele->next;
    }
    cout << endl;
    return 0;
}