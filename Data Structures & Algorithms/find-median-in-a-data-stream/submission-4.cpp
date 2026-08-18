class MedianFinder {
public:
priority_queue<int>max_heap;
priority_queue<int,vector<int>,greater<int>>min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(min_heap.empty() || num<max_heap.top()){
            max_heap.push(num);
        }
        else{
            min_heap.push(num);
        }
        //always make usre that maxheap ka size ek bada hai min heap se ya equal 
        if(max_heap.size()>min_heap.size()+1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(max_heap.size()<min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size()==min_heap.size()){
            //even hai
            return (max_heap.top()+min_heap.top() )/2.0;
        }
        else{
            return max_heap.top();
        }
    }
};
