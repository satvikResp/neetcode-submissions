/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mymap;
    Node* dfs(Node *node){
    
    if(mymap.find(node)!=mymap.end()){
        return mymap[node];
    }
    Node *clone=new Node(node->val);

    mymap[node]=clone;

    for(Node* n:node->neighbors){
        clone->neighbors.push_back(dfs(n));
    }
    return clone;
    }


    Node* cloneGraph(Node* node) {
         if(node == nullptr)
            return nullptr;
       return dfs(node);
    }
};
