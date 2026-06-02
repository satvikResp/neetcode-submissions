class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j=s.size()-1;
        int left=-1;
        int right=-1;

        bool ispal=true;
        
        while(i<j){
            if(s[i]!=s[j]){
                left=i+1;
                right=j-1;
                ispal=false;
                break;
            }
            i++;
            j--;
        }
        if(ispal){
            return true;
        }
        else{
            int oldi=i;
            int oldj=j;
            ispal=true;
            //left removed
            while(left<j){
                if(s[left]!=s[j]){
                    ispal=false;
                    break;
                }
                left++;
                j--;
            }
            if(ispal==true){
                return true;
            }
            else{
                //right removed
                while(oldi<right){
                    if(s[oldi]!=s[right]){
                        return false;
                    }
                    oldi++;
                    right--;
                }
            }
        }
        return true;
    }
};