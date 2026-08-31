class Solution {
public:
    void func(vector<int>&arr,int k,vector<vector<int>>&ans,vector<int>&res,int i){
        if(res.size()==k){
            ans.push_back(res);
            return;
        }
        if(i>=arr.size()){
            return;
        }
        //take
        res.push_back(arr[i]);
        func(arr,k,ans,res,i+1);
        res.pop_back();

        //not take
        func(arr,k,ans,res,i+1);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }

        vector<vector<int>>ans;
        vector<int>res;
        
        func(arr,k,ans,res,0);
        return ans;
    }
};