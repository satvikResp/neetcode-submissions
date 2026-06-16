class Solution {
public:
    bool check(unordered_map<char,int>&mymap){
        
        for(auto it:mymap){
            if(it.second>0){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }
        unordered_map<char,int>mymap;
        for(int i=0;i<t.size();i++){
            mymap[t[i]]++;
        }
        int i=0,j=0;
        int len=0;
        int tempi=0,tempj=0,diff=INT_MAX;
        while(j<s.size()){
            if(mymap.contains(s[j])){
                mymap[s[j]]--;
            }

            while(check(mymap)){
                if(diff>j-i+1){
                    tempi=i;
                    tempj=j;
                    diff=tempj-tempi+1;
                }
                if(mymap.contains(s[i])){
                    mymap[s[i]]++;
                }
                i++;
            }
            j++;
        }
        string word="";
        if(diff==INT_MAX){
            return word;
        }
        for(int k=tempi;k<=tempj;k++){
            word+=s[k];
        }
        return word;
    }
};