class Solution {
public:
    bool isPalindrome(string &s){
        string temp=s;
        reverse(temp.begin(),temp.end());
        if(temp==s) return true;
        return false;
    }
    void func(vector<vector<string>>&ans,string s,int idx,vector<string>&res){
        if(idx==s.size()){
            ans.push_back(res);
            return;
        }
        for(int i=idx;i<s.size();i++){
            string sub_string=s.substr(idx,i-idx+1); //ek kam hi leta hai kyunki ye
            if(isPalindrome(sub_string)){
                res.push_back(sub_string);
                func(ans,s,i+1,res);
                res.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        func(ans,s,0,res);
        return ans;
    }
};
