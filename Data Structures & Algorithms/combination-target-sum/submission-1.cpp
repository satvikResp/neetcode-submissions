class Solution {
public:
    void getnumbers(vector<int>& candidates, int target,vector<int>& ansarr, int idx,vector<vector<int>>&finalarr){
        if(target==0){
            finalarr.push_back(ansarr);
            return;
        }
        if(target<0){
            return;
        }
        if(idx>=candidates.size()){
            return;
        }
        //take
        ansarr.push_back(candidates[idx]);
        getnumbers(candidates, target-candidates[idx],ansarr,idx,finalarr);
        
        //not take
      
        ansarr.pop_back();
        getnumbers(candidates, target,ansarr,idx+1,finalarr);
        
    }   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ansarr;
        vector<vector<int>>finalarr;
        getnumbers(candidates,target,ansarr,0,finalarr);
        return finalarr;
    }
};


 