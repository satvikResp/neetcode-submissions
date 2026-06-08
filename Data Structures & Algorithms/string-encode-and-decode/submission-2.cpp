class Solution {
public:

    string encode(vector<string>& strs) {
        string word="";
        for(int i=0;i<strs.size();i++){
            word+=to_string(strs[i].size())+'#'+strs[i];
        }
        return word;
    }

    vector<string> decode(string s) {
        string len="";
        int wordlen=0;
        string res="";
        vector<string>ans;
        int i=0;
        
        while(i<s.size()){
            len="";
            res="";
            while(s[i]!='#'){
                len+=s[i];
                i++;
            }
            i++;
            wordlen=stoi(len);
            res+=s.substr(i,wordlen);
            ans.push_back(res);
            i+=wordlen;
        
        }
        return ans;
    }
};
