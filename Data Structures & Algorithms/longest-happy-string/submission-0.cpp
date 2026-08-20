class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int, char>> heap;
        if(a!=0)
        heap.push({a, 'a'});
        if(b!=0)
        heap.push({b, 'b'});
        if(c!=0)
        heap.push({c, 'c'});

        string ans = "";

        pair<int, char> temp = {0, '#'};
        char first = '#';   // second last
        char second = '#';  // last

        while (!heap.empty()) {

            // top character se 3 consecutive banenge
            if (heap.top().second == first &&
                heap.top().second == second) {

                temp = heap.top();
                heap.pop();

                // koi alternate character nahi hai
                if (heap.empty())
                    break;

                // alternate character use karo
                pair<int, char> var = heap.top();
                heap.pop();

                ans += var.second;
                var.first--;

                first = second;
                second = var.second;

                if (var.first > 0)
                    heap.push(var);

                // blocked character wapas heap mein
                heap.push(temp);

                continue;
            }

            // normal case
            pair<int, char> var = heap.top();
            heap.pop();

            ans += var.second;
            var.first--;

            first = second;
            second = var.second;

            if (var.first > 0)
                heap.push(var);
        }

        return ans;
    }
};