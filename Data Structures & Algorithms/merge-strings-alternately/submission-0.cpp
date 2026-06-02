class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        string word="";
        while(i<word1.size() && j<word2.size()){

            word+=word1[i];
            i++;
            word+=word2[j];
            j++;
        }
        while(i<word1.size()){
            word+=word1[i];
            i++;
        }
        while(j<word2.size()){
            word+=word2[j];
            j++;
        }
        return word;
    }
};