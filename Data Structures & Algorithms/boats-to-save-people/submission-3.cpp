class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0;
        int j=people.size()-1;
        int boat=0;
        sort(people.begin(),people.end());
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