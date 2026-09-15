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
    
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node* ,Node*>cloned;
        queue<Node*>q;
        cloned[node]=new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            for(Node *n:curr->neighbors){
                if(cloned.find(n)==cloned.end()){
                    cloned[n]=new Node(n->val);
                    q.push(n);
                }
                cloned[curr]->neighbors.push_back(cloned[n]);
            }
        }
        return cloned[node];
    }
};
