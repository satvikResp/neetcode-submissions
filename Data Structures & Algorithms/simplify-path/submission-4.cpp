class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string>stk;
        while(getline(ss,token,'/')){
            if(token=="." || token==""){
                continue;
            }
            else if(token==".."){
                if(!stk.empty()){
                    stk.pop_back();
                }
            }
            else{
                stk.push_back(token);
            }
        }
        string result="";
        for(auto i:stk){
            result+="/";
            result+=i;
        }
        if(result==""){
            result+="/";
        }
        return result;
    }
};