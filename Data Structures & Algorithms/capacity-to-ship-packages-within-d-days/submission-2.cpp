class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while (l < r) {
            int mid = l + (r - l) / 2;

            int day = 1, load = 0;

            for (int w : weights) {
                if (load + w <= mid) {
                    load += w;
                } else {
                    day++;
                    load = w;
                }
            }

            if (day <= days) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};