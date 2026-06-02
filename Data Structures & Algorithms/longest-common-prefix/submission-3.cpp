class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix=strs[0];
        int j=0;
        for(int i=1;i<strs.size();i++){
            j=0;
         while(j<min(prefix.size(),strs[i].size())){
            if(strs[i][j]!=prefix[j]){
                break;
            }
            j++;
         }
           prefix = prefix.substr(0,j);
        }
        return prefix;
    }
};