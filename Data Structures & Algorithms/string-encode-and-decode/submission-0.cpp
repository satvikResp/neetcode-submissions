class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for(int i = 0; i < strs.size(); i++){
            res += to_string(strs[i].size()) + ",";
        }

        res += "#";

        for(int i = 0; i < strs.size(); i++){
            res += strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        vector<int> sizes;

        int i = 0;

        while(s[i] != '#'){
            string num = "";

            while(s[i] != ','){
                num += s[i];
                i++;
            }

            sizes.push_back(stoi(num));
            i++;
        }

        i++; // skip '#'

        for(int j = 0; j < sizes.size(); j++){
            string word = s.substr(i, sizes[j]);
            ans.push_back(word);
            i += sizes[j];
        }

        return ans;
    }
};