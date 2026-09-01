class Solution {
public:
    void func(vector<string>&ans,string res,int open,int close,int &n){
        if(res.size()==2*n){
            ans.push_back(res);
            return;
        }
        if(open<n){
            res+='(';
            func(ans,res,open+1,close,n);
            res.pop_back();
        }
        if(close<open){
            res+=')';
            func(ans,res,open,close+1,n);
            res.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string res;
        func(ans,res,0,0,n);
        return ans;
    }
};
