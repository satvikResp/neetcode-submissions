class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mymap1;
        unordered_map<char,int>mymap2;
        for(int i=0;i<s.size();i++){
                mymap1[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
                mymap2[t[i]]++;
        }
        if(mymap1==mymap2){
            return true;
        }
        else{
            return false;
        }
    }
};
