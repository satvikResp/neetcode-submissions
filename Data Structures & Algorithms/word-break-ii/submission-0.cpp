class Solution {
public:
    void func(string &s, vector<string>& dict,int idx,string &ans,vector<string>&res){
        if(idx>=s.size()){
            string temp=ans;
            temp.erase(temp.size()-1);
            res.push_back(temp);
            return ;
        }

        for(int i=idx;i<s.size();i++){
            // if(find(dict.begin(),dict.end(),s.substr(idx,s.size()-idx))!=dict.end()) return true;
            string substring=s.substr(idx,i-idx+1);
            if(find(dict.begin(),dict.end(),substring)!=dict.end()){
                ans+=substring;
                ans+=" ";
                func(s,dict,i+1,ans,res);
                ans.erase(ans.size()-substring.size()-1);
            }
        }
        return ;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int idx=0;
        string ans;
        vector<string>res;
        func(s,wordDict,idx,ans,res);
     
        return res;
    }
};
