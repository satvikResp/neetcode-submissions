class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>heap;
        for(auto it:nums){
            heap.push(it);
        }
        int i=1;
        while(i<k){
            heap.pop();
            i++;
        }
        return heap.top();
    }
};
