#include<bits/stdc++.h>

using namespace std;

class node {
public:
    int key; int val;
    node* prev;
    node* next;

    node() {
        this->key = 0;
        this->val = 0;
        prev = NULL;
        next = NULL;
    }

    node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    node* head = new node(); //most recently used
    node* tail = new node(); //least recently used

    int cap;
    unordered_map<int, node*> cache;

        void remove(node* curr) {
        node* prev = curr->prev;
        node* next = curr->next;
        
        prev->next = curr->next;
        next->prev = curr->prev;
    }

    void insert(node* curr) {
        node* prev = head;
        node* next = head->next;

        prev->next = curr;
        next->prev = curr;
        curr->prev = prev;
        curr->next = next;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        cache[key] = new node(key, value);
        insert(cache[key]);
        if(cache.size() > cap) {
            cache.erase(tail->prev->key);
            remove(tail->prev);
        }
    }
};

int main() {
    int capacity = 2;
    LRUCache* obj = new LRUCache(capacity);
    obj->put(1,1);
    obj->put(2,2);
    cout << obj->get(1) << endl;
    obj->put(3,3);
    cout << obj->get(2) << endl;
    obj->put(4,4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
    return 0;
}