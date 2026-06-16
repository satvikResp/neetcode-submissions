class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int min=INT_MAX;
        int minindex=-1;
        vector<int>temparr(arr.size());
        for(int i=0;i<arr.size();i++){
            temparr[i]=abs(x-arr[i]);
        }
        vector<int>ans;
        for (int j=0;j<k;j++){

        for(int i=0;i<temparr.size();i++){
            if(temparr[i]==INT_MAX){
                continue;
            }
            if(min>temparr[i]){
                min=temparr[i];
                minindex=i;
                 
            }
            else if(min==temparr[i]){
                if(arr[minindex]>arr[i]){
                    min=temparr[i];
                    minindex=i;
                }
            }
        }
        ans.push_back(arr[minindex]);
        temparr[minindex]=INT_MAX;
        minindex=-1;
        min=INT_MAX;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};