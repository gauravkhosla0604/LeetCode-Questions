class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        queue<int> q;

        for(int i=0;i<n;i++){
            if(color[i]!=-1) continue;

            q.push(i);
            color[i]=0;

            while(!q.empty()){
                int curr=q.front();
                q.pop();

                for(int v:graph[curr]){
                    if(color[v]==-1){
                        color[v]=!color[curr];
                        q.push(v);
                    }else{
                        if(color[v]==color[curr]){
                            return false;
                        }
                    }
                }
            }
           
        }
        return true;
        
    }
};