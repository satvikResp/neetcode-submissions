class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>map;
		for(auto it:tasks){
			map[it]++;
		}

		//map = char,freq

		priority_queue<pair<int,char>>heap;
		for(auto it:map){
			heap.push({it.second,it.first});
		}

		//heap = freq,char

		queue<pair<int,pair<char,int>>>st;

		//stack = counter character freq
		int cnt=0;
		while(!heap.empty() || !st.empty()){
			cnt++;

			while(!st.empty() && st.front().first<=cnt){
				heap.push({st.front().second.second,st.front().second.first});
				st.pop();
			}
			if(!heap.empty()){
			if(heap.top().first-1<=0) {
				heap.pop();
				continue;
			}
			st.push({cnt+n+1,{heap.top().second,heap.top().first-1}});
			heap.pop();
			}
			else continue;
		}
		return cnt;
    }
};
