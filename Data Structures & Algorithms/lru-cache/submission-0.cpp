class Node{
    public:
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int k,int v){
        key=k;
        val =v;
        next=nullptr;
        prev=nullptr;
    }
};

class LRUCache {
public:
Node *left;
Node *right;
int sizeofmem;
unordered_map<int,int>cache;
    LRUCache(int capacity) {
        left=new Node(0,0);
        right=new Node(0,0);
        left->next=right;
        right->prev=left;
        sizeofmem=capacity;
    }
    void insert(int key ,int val){
        Node *nayanode=new Node(key,val);
        right->prev->next=nayanode;
        nayanode->next=right;
        nayanode->prev=right->prev;
        right->prev=nayanode;
    }
    void movenode(int k,int v){
        Node *temp=left->next;

        while(temp!=right && temp->key!=k ){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

        right->prev->next=temp;
        temp->next=right;
        temp->prev=right->prev;
        right->prev=temp;
    }
    void removenode(){
        Node *temp=left->next;
        
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        int key=temp->key;
        cache.erase(key);
        delete temp;
    }
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            //update the ll
            
            movenode(key,cache[key]);
            return cache[key];
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            cache[key]=value;
            movenode(key,value);
        }
        else{
            cache[key]=value;
            insert(key,value);
        }
        if(cache.size()>sizeofmem){
            removenode();
        }
    }
};
