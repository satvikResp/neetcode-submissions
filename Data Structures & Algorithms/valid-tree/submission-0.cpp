class Solution {
public:
    bool dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& visited) {

        visited[node] = 1;

        for(auto it : adj[node]) {

            if(!visited[it]) {

                if(dfs(it, node, adj, visited))
                    return true;
            }
            else if(it != parent) {
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n, 0);

        // Check cycle
        if(dfs(0, -1, adj, visited))
            return false;

        // Check connectivity
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                return false;
        }

        return true;
    }
};