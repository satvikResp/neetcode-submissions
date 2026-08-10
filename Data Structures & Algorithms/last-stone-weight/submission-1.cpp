class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>heap;
        for(auto it:stones){
            heap.push(it);
        }
        while(heap.size()>1){
        int first=heap.top();
        heap.pop();
        int second=heap.top();
        heap.pop();
        if(first==second) continue;
        else if(first<second){
            heap.push(second-first);
        }
        else{
            heap.push(first-second);
        }
       
        }
        if(heap.size()==0) return 0;
        return heap.top();
    }
};
