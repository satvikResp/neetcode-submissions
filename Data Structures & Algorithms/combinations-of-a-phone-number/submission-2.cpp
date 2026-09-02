class Solution {
public:
    void func(vector<string>& ans, string& digits, string& res,
              unordered_map<int, string>& mymap) {
        if (digits.size() == 0) {
            ans.push_back(res);
            return;
        }
        string idx = digits.substr(0, 1); // 3 nikala
        string naklidigit=digits;
        naklidigit.erase(0, 1);               // 3 digits se remove krdiya
        int index = stoi(idx);            // convert kiya 3 ko int me
        string word = mymap[index];       // map se 3 ke shabd nikale     def
        for (int i = 0; i < word.size(); i++) { // ek ek shabd lena hai isme se
            res += word[i];                     // phla le liya d
            func(ans, naklidigit, res,mymap); // ab agla lene ke liye call lgayi 4 me se
            res.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> ans;
        string res;
        unordered_map<int, string> mymap;
        mymap[2] = "abc";
        mymap[3] = "def";
        mymap[4] = "ghi";
        mymap[5] = "jkl";
        mymap[6] = "mno";
        mymap[7] = "pqrs";
        mymap[8] = "tuv";
        mymap[9] = "wxyz";
        func(ans, digits, res, mymap);
        return ans;
    }
};
