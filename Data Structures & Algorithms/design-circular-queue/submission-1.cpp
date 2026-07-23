class MyCircularQueue {
public:
    vector<int>queue;
    int capacity;
    int rear;
    int front;
    int size;
    MyCircularQueue(int k) {
        queue=vector<int>(k);
        capacity =k;
        rear=-1;
        front =0;
        size=0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
         rear=(rear+1)%capacity;
        queue[rear]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front=(front+1)%capacity;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty()? -1 :queue[front];
    }
    
    int Rear() {
        return isEmpty()? -1:queue[rear];
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(size==capacity){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */