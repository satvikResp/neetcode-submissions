class Node {
public:
    int key, val, freq;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        val = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class DLL {
public:
    Node *left, *right;
    int size;

    DLL() {
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
        size = 0;
    }

    void insert(Node *node) {
        Node *prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
        size++;
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node* removeLRU() {
        Node *node = left->next;
        remove(node);
        return node;
    }
};

class LFUCache {
public:
    int capacity;
    int minFreq;

    unordered_map<int, Node*> nodeMap;
    unordered_map<int, DLL*> freqMap;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node *node) {

        int f = node->freq;

        freqMap[f]->remove(node);

        if (f == minFreq && freqMap[f]->size == 0)
            minFreq++;

        node->freq++;

        if (!freqMap.count(node->freq))
            freqMap[node->freq] = new DLL();

        freqMap[node->freq]->insert(node);
    }

    int get(int key) {

        if (!nodeMap.count(key))
            return -1;

        Node *node = nodeMap[key];
        updateFreq(node);

        return node->val;
    }

    void put(int key, int value) {

        if (capacity == 0)
            return;

        if (nodeMap.count(key)) {
            Node *node = nodeMap[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        if (nodeMap.size() == capacity) {

            Node *node = freqMap[minFreq]->removeLRU();

            nodeMap.erase(node->key);
            delete node;
        }

        Node *node = new Node(key, value);

        if (!freqMap.count(1))
            freqMap[1] = new DLL();

        freqMap[1]->insert(node);

        nodeMap[key] = node;

        minFreq = 1;
    }
};