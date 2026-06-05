class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0;
        int j=people.size()-1;
        int boat=0;
        // sort(people.begin(),people.end());
        unordered_map<int,int>mymap;
        for(int i=0;i<people.size();i++){
            mymap[people[i]]++;
        }
        int index=0;
        int maxi=*max_element(people.begin(),people.end());
        int mini=*min_element(people.begin(),people.end());

        for(int i=mini;i<=maxi;i++){
            if(mymap.find(i)!=mymap.end()){
                while(mymap[i]!=0){
                    people[index]=i;
                    mymap[i]--;
                    index++;
                }
            }
        }
        
        while(i<j){
            if(people[i]+people[j]<=limit){
                boat++;
                i++;
                j--;
            }
            else {
                boat++;
                j--;
            }
            
        }
        if(i==j){
            boat++;
        }
        return boat;
    }
};