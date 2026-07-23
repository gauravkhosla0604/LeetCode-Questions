class Solution {
public:
    bool dfs(int src,int dest,vector<vector<int>> &adj,vector<bool> &vis){
        if(src==dest){
            return true;
        }
        vis[src]=true;
        for(int nei:adj[src]){
            if(!vis[nei]){
                if(dfs(nei,dest,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,false);
        return dfs(source,destination,adj,vis);
        
    }
};