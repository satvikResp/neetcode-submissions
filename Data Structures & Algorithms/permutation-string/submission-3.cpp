class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>freqarr;
        unordered_map<char,int>freqarr2;
        for(int i=0;i<s1.size();i++){
            freqarr[s1[i]]++;
        }
        int k=s1.size();
        
        int j=0;
        for(int i=0;i<s2.size();i++){
            
           freqarr2[s2[i]]++;

           if(i-j+1>k){
            if(freqarr2[s2[j]]>1){
                freqarr2[s2[j]]--;
            }
            else{
                freqarr2.erase(s2[j]);
            }
            j++;
           }
           if(i-j+1==k){
            if(freqarr==freqarr2){
                return true;
            }
           }
        }
        return false;
    }
};
