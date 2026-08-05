class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD=1e9+7;
        vector<vector<pair<int,int>>> adj(n);

        for(auto &road:roads){
            int u=road[0];
            int v=road[1];
            int t=road[2];

            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        dist[0]=0;
        ways[0]=1;

        pq.push({0,0});
        while(!pq.empty()){
            auto[d,node]=pq.top();
            pq.pop();

            if(d>dist[node]){
                continue;
            }
            for(auto &[next,time]:adj[node]){
                long long newDist=d+time;

                if(newDist<dist[next]){
                    dist[next]=newDist;
                    pq.push({newDist,next});
                    ways[next]=ways[node];
                }else if(newDist==dist[next]){
                    ways[next]=(ways[next]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};