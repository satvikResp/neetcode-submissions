class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        map<string,vector<string>>mymap;

        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mymap[temp].push_back(strs[i]);
        }
        for(auto it :mymap){
            result.push_back(it.second);
        }
        return result;
    }
};