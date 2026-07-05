class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mymap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mymap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if (mymap.find(key) == mymap.end())
        return "";

        int l=0;
        int r=mymap[key].size()-1;
        string ans="";
        while(l<=r){
            int m=l+(r-l)/2;
            if(mymap[key][m].first<=timestamp){
                ans= mymap[key][m].second;
                l=m+1;
            }
            else {
                r=m-1;
            }
        }
        return ans;
    }
};
