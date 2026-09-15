class Solution {
public:
    vector<vector<int>>direction{{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(fresh==0) return 0;
        int time=0;
        while(!q.empty()){
           int n=q.size();
           while(n--){
            auto curr=q.front();
            q.pop();
            int i=curr.first;
            int j=curr.second;

            for(auto dir:direction){
                int new_i=i+dir[0];
                int new_j=j+dir[1];

                if(new_i>=0 && new_i<grid.size() && new_j>=0 && new_j<grid[0].size() && grid[new_i][new_j]==1){
                    grid[new_i][new_j]=2;
                    fresh--;
                    q.push({new_i,new_j});
                }
            }
            }
           time++;
            
        }
        if(fresh==0) return time-1; //because ek extra time add ho jata hai last me jab koi bhi nhi bacha hota condition check hone se pehle
        else return -1;
    }
};
