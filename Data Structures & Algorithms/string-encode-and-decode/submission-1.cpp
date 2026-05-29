class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(int i=0;i<strs.size();i++){
            encoded+=to_string(strs[i].size())+"#"+strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>decoded;
        int i=0;
        int j=0;
        while(i<s.size()){
        string lenofstr="";
        string temp="";
        j=i;
        while(s[j]!='#'){
            lenofstr+=s[j];
            j++;
        }
        j++; //now j at first char of a word
        int len=stoi(lenofstr);
        temp+=s.substr(j,len);

        decoded.push_back(temp);
        i = j+len;
        }
        return decoded;
    }
};
