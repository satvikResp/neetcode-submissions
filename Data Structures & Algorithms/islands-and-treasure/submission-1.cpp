class Solution {
public:
    int INF=2147483647;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int step=1;
        while(!q.empty()){
            int n=q.size();
           
            while(n--){
                auto curr=q.front();
                q.pop();
                int i=curr.first;
                int j=curr.second;
                
                for(auto dir:directions){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];

                    if(new_i>=0 && new_i<grid.size() && new_j>=0 && new_j<grid[0].size() && grid[new_i][new_j]==INF){
                        grid[new_i][new_j]=step;
                        q.push({new_i,new_j});
                    }
                }
            }
            step++;
        }
    }
};
