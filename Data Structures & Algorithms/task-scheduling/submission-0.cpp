class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int interval=0;
		unordered_map<char,int>map;
		for(auto it:tasks) map[it]++;
		priority_queue<pair<int,char>>heap; // freq kitni bach rhi hai , character
		queue<pair<pair<int,char>,int>> q;   // freq ,character ,release time
		for(auto it : map) {
			heap.push({it.second, it.first});
		}

		 
		do {
			interval++;

			while(!q.empty() && q.front().second<=interval) {
				heap.push({q.front().first.first,q.front().first.second});
				q.pop();
			}

			if(heap.empty()) continue;

			if(heap.top().first-1<=0) {
				heap.pop();
				continue;
			}

			pair<pair<int,char>,int> qvalue = {
				{heap.top().first - 1, heap.top().second},
				interval + n + 1
			};

			q.push(qvalue);
			heap.pop();

		} while(!q.empty() || !heap.empty());
        return interval;
	}
};
