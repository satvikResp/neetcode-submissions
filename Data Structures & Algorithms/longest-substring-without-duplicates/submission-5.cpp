class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>mymap;
        int i=0;
        int len=0;
        int maxlen=0;
        for(int j=0;j<s.size();j++){
            if(mymap.find(s[j])!=mymap.end() && mymap[s[j]]>=i){
                len=j-i;
                i=mymap[s[j]]+1;
                mymap[s[j]]=j;
                maxlen=max(maxlen,len);
            }
            else{
                mymap[s[j]]=j;
                len = j - i + 1;
                maxlen = max(maxlen, len);
            }
            
            
        }
        return maxlen;
    }
};
