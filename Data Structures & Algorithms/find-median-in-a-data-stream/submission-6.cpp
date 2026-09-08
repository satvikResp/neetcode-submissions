class MedianFinder {
public:
    priority_queue<double>left_max;
    priority_queue<double,vector<double>,greater<double>>right_min;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(left_max.empty() && right_min.empty()){
            left_max.push(num);
            return;
        }

        if(!left_max.empty() && num>left_max.top()){
            right_min.push(num);
        }
        else{
            left_max.push(num);
        }

        if(left_max.size() > right_min.size() + 1)
        {
            right_min.push(left_max.top());
            left_max.pop();
        }

        if(right_min.size() > left_max.size())
        {
            left_max.push(right_min.top());
            right_min.pop();
        }

    }
    
    double findMedian() {
        if(left_max.size()==right_min.size()){
            return (left_max.top() + right_min.top())/2;
        }

        else{
            return left_max.top();
        }
    }
};
