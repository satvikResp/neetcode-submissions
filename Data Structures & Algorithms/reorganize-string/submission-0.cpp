class Solution {
public:
    string reorganizeString(string s) {

        //map = char int 
        unordered_map<char,int>mymap;
        for(auto it:s){
            mymap[it]++;
        }
        //heap = int char
        priority_queue<pair<int,char>>heap;

       
        for(auto it:mymap){
            heap.push({it.second,it.first});
        }
        pair<int,char>prev={0,'#'};
        string ans;
        while(!heap.empty()){
            auto ch=heap.top();
            ans+=ch.second;
            heap.pop();
            if(prev.second!='#'){
                heap.push(prev);
                prev={0,'#'};
            }
            if(ch.first-1<=0) continue;
            else prev={ch.first-1,ch.second};
        }
        if(ans.size()!=s.size()) return "";
        return ans;
    }
};