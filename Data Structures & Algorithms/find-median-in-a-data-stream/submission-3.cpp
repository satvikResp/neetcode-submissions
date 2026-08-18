class MedianFinder {
public:
    vector<int> arr;

    MedianFinder() {}

    void addNum(int num) {
        arr.push_back(num);

        int i = arr.size() - 2;

        while(i >= 0 && arr[i] > num) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = num;
    }

    double findMedian() {
        if(arr.size() % 2 == 0) {
            int mid = arr.size() / 2;
            return (arr[mid] + arr[mid-1]) / 2.0;
        }
        else {
            return arr[arr.size()/2];
        }
    }
};