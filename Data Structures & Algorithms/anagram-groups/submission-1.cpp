class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mymap;
        
        for(int i=0;i<strs.size();i++){
            vector<int>countarr(26,0);
            string word=strs[i];
            for(auto it :word){
                countarr[it-'a']++;
            }

            //creating the temp like aet =[eat,tea], so here we make aet but of numbers at idx 0->1,2->0,3->0,4->0,5->1....

            string temp="";
            for(int j=0;j<26;j++){
            temp += to_string(countarr[j]) + ","; // agr 10 a aagye to confusion hogi jese 101... yhan pe 10 a ki jgah 1 a and 0 b lg skta hai
            }

            //ab bangya hai to jo same hai iske jasie usko hashmap me dalo 
            mymap[temp].push_back(strs[i]);
        }
             // ab bngya sare map to usko answer array me daldo
             vector<vector<string>>ansarr;
            for(auto it:mymap){
                ansarr.push_back(it.second);
            }
            return ansarr;
    }
};