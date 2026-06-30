class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int weight = 1;

        while (true) {
            int cdw = 0;
            int daycnt = 1;
            bool fullytraversed = true;

            int i = 0;

            while (i < weights.size()) {

                if (weights[i] > weight) {
                    fullytraversed = false;
                    break;
                }

                if (cdw + weights[i] <= weight) {
                    cdw += weights[i];
                    i++;
                } else {
                    daycnt++;
                    cdw = 0;
                }
            }

            if (fullytraversed && daycnt <= days) {
                return weight;
            }

            weight++;
        }
    }
};