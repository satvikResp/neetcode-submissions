class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++){
           s[i]= tolower(s[i]);
        }
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]==' '||!isalnum(s[i])){
                i++;
                continue;
            }
            if(s[j]==' '||!isalnum(s[j])){
                j--;
                continue;
            }

            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
