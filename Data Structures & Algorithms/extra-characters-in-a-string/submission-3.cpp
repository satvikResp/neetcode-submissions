class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isEnd=false;
    }
};

class Solution {
public:

    vector<int> dp;

    int func(TrieNode *root, string s, int idx){

        if(idx >= s.size()){
            return 0;
        }

        // DP: agar is idx ka answer already nikala hai
        if(dp[idx] != -1){
            return dp[idx];
        }

        TrieNode *curr = root;

        // Current character ko extra maan lo
        int ans = 1 + func(root, s, idx + 1);

        for(int j=idx; j<s.size(); j++){

            int i = s[j] - 'a';

            // Trie me word aage nahi ban raha
            if(curr->children[i] == nullptr){
                break;
            }

            curr = curr->children[i];

            // Ek dictionary word mil gaya
            if(curr->isEnd == true){

                // idx se j tak ka word consume ho gaya
                int aagekaextra = func(root, s, j + 1);

                ans = min(ans, aagekaextra);
            }
        }

        // Is idx ka final answer store
        return dp[idx] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {

        TrieNode *root = new TrieNode();

        // Trie banana
        for(auto word : dictionary){

            TrieNode *curr = root;

            for(int i=0; i<word.size(); i++){

                int idx = word[i] - 'a';

                if(curr->children[idx] == nullptr){
                    curr->children[idx] = new TrieNode();
                }

                curr = curr->children[idx];
            }

            curr->isEnd = true;
        }

        // DP initialize
        dp.resize(s.size(), -1);

        return func(root, s, 0);
    }
};