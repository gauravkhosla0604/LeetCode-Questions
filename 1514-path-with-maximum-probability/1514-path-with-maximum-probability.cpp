class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> adj;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succProb[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        vector<double> prob(n,0.0);
        priority_queue<pair<double,int>> pq;

        prob[start]=1.0;
        pq.push({1.0,start});

        while(!pq.empty()){
            double currProb=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &[next,edgeProb]:adj[node]){
                double newProb=currProb*edgeProb;
                if(newProb>prob[next]){
                    prob[next]=newProb;
                    pq.push({newProb,next});
                }
            }
        }
        return prob[end];
        
    }
};