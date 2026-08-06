class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        dist[0][0]=grid[0][0];
        pq.push({grid[0][0],0,0});

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();

            int time=curr[0];
            int r=curr[1];
            int c=curr[2];

            if(time>dist[r][c]){
                continue;
            }
            if(r==n-1 && c==n-1){
                return time;
            }
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr<0 || nr>=n || nc<0 || nc>=n){
                    continue;
                }
                int newTime=max(time,grid[nr][nc]);
                if(newTime<dist[nr][nc]){
                    dist[nr][nc]=newTime;
                    pq.push({newTime,nr,nc});
                }
            }
        }
        return -1;
    }
};