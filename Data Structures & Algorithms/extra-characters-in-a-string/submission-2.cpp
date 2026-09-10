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

        // base
        if(idx >= s.size()){
            return 0;
        }

        // already calculated
        if(dp[idx] != -1){
            return dp[idx];
        }

        TrieNode *curr = root;

        // current character ko extra maan lo
        int ans = 1 + func(root, s, idx + 1);

        // dictionary word dhundho
        for(int j=idx; j<s.size(); j++){

            int i=s[j]-'a';

            if(curr->children[i] == nullptr){
                break;
            }

            curr=curr->children[i];

            if(curr->isEnd == true){

                int aagekaextra=func(root, s, j+1);

                ans=min(ans, aagekaextra);
            }
        }

        return dp[idx]=ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {

        TrieNode *root=new TrieNode();

        // Trie banana
        for(auto word:dictionary){

            TrieNode *curr=root;

            for(int i=0;i<word.size();i++){

                int idx=word[i]-'a';

                if(curr->children[idx]==nullptr){
                    curr->children[idx]=new TrieNode();
                }

                curr=curr->children[idx];
            }

            curr->isEnd=true;
        }

        // memoization array
        dp.resize(s.size(),-1);

        return func(root,s,0);
    }
};