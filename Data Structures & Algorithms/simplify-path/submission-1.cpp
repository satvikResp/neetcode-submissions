class Solution {
public:
    string simplifyPath(string path) {
        int i=0;
        stack<string>st;
        while(i<path.size()){
            string word="";
            while(i<path.size() && path[i]!='/'){
                word+=path[i];
                i++;
            }
            if(st.empty()&& word.size()>=1){
                if(word[0]=='.'){
                    if(word.size()==2){
                        //peche delete kuch nhi ho skata to kuch mat kro
                        continue;
                    }
                    else if(word.size()==1){
                        //do nothing 
                        continue;
                    }
                    else{
                        //delete krne wale chijhi nhi hai 
                        st.push(word);
                    }
                }
                else{
                    st.push(word);
                }
            }
            else if(!st.empty()&& word.size()>=1){
                if(word[0]=='.'){
                    if(word.size()==2){
                        //peche delete krna hai 
                        st.pop();
                    }
                    else if(word.size()==1){
                        //do nothing 
                        continue;
                    }
                    else{
                        st.push(word);
                    }
                }
                else{
                    st.push(word);
                }
            }
            i++;
        }
        string ans="";
        if(st.empty()){
            ans+='/';
        }
        else{
            stack<string>temp;
            while(!st.empty()){
                temp.push(st.top());
                st.pop();
            }
            st=temp;
            while(!st.empty()){
                ans+='/';
                ans+=st.top();
                st.pop();
            }
        }
        return ans;
    }
};