class Solution {
public:
    vector<int> ans;
    int findPar(int u,vector<int> &par){
        if(par[u]==u) return u;
        return par[u]=findPar(par[u],par);
    }
    void unionF(int u,int v,vector<int> &par,vector<int> &rank){
        int pu=findPar(u,par);
        int pv=findPar(v,par);

        if(pu==pv){
            ans.push_back(u);
            ans.push_back(v);
            return;
        }
        if(rank[pu]==rank[pv]){
            par[pv]=pu;
            rank[pu]++;
        }else if(rank[pu]>rank[pv]){
            par[pv]=pu;
        }else{
            par[pu]=pv;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> par(n+1);
        vector<int> rank(n,0);

        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            unionF(u,v,par,rank);
        }
        return ans;
    }
};