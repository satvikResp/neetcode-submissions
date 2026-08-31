
class Solution { 
public: 
    vector<vector<int>> combine(int n, int k) { 
        vector<vector<int>> ans; 
        vector<int> res; 

        func(n, k, ans, res, 1); 
        return ans; 
    } 

    void func(int n, int k, vector<vector<int>>& ans, vector<int>& res, int i) { 
        
        if(i > n){ 
            if(res.size() == k){ 
                ans.push_back(res); 
            }
            return; 
        } 

        // take
        res.push_back(i); 
        func(n, k, ans, res, i + 1); 
        res.pop_back(); 

        // not take
        func(n, k, ans, res, i + 1); 
    } 
};

