class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>s1map;
        for(int i=0;i<s1.size();i++){
            s1map[s1[i]]++;
        }
        unordered_map<char,int>s2map;
        for(int i=0;i<s2.size();i++){
            
            for(int j=i;j<min(i+s1.size(),s2.size());j++){
                
                s2map[s2[j]]++;
            }
            if(s1map==s2map){
                    return true;
             }
             s2map.clear();
        }
        return false;
    }
};
