class Solution { 
public: 
    void func(int n, int k, vector<vector<int>>& ans, 
        vector<int>& res, int i) { 

        if(res.size() == k) { 
            ans.push_back(res); 
            return; 
        } 

        for(int j = i; j <= n; j++) { 
            res.push_back(j); 

            func(n, k, ans, res, j + 1); 

            res.pop_back(); 
        }
    } 

    vector<vector<int>> combine(int n, int k) { 
        vector<vector<int>> ans; 
        vector<int> res; 

        func(n, k, ans, res, 1); 

        return ans; 
    } 
};