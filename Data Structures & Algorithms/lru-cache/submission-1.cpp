#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    Node* left;
    Node* right;
    int sizeofmem;
    unordered_map<int, Node*> cache;

    LRUCache(int capacity) {
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
        sizeofmem = capacity;
    }

    void insert(Node* node) {
        right->prev->next = node;
        node->next = right;
        node->prev = right->prev;
        right->prev = node;
    }

    void movenode(Node* temp) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        right->prev->next = temp;
        temp->next = right;
        temp->prev = right->prev;
        right->prev = temp;
    }

    void removenode() {
        Node* temp = left->next;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        cache.erase(temp->key);
        delete temp;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        Node* temp = cache[key];
        movenode(temp);
        return temp->val;
    }

    void put(int key, int value) {

        if (cache.find(key) != cache.end()) {

            Node* temp = cache[key];
            temp->val = value;
            movenode(temp);

        } else {

            Node* node = new Node(key, value);
            cache[key] = node;
            insert(node);

            if (cache.size() > sizeofmem) {
                removenode();
            }
        }
    }
};