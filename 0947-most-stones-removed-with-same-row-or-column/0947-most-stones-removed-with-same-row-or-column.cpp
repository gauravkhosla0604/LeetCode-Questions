class Solution {
public:
    vector<int> par,rank;

    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]);
    }
    void unite(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b){
            return;
        }
        if(rank[a]>rank[b]){
            par[b]=a;
        }else if(rank[a]<rank[b]){
            par[a]=b;
        }else{
            par[b]=a;
            rank[a]++;
        }

    }
    int removeStones(vector<vector<int>>& stones) {
        int OFFSET = 10001;

        par.resize(20002);
        rank.resize(20002, 0);

        for(int i=0;i<20002;i++){
            par[i]=i;
        }
        unordered_set<int> nodes;
        for(auto& stone:stones){
            int row=stone[0];
            int col=stone[1]+OFFSET;

            unite(row,col);

            nodes.insert(row);
            nodes.insert(col);
        }
        int components=0;

        for(int node:nodes){
            if(find(node)==node){
                components++;
            }
        }
        return stones.size()-components;
        
    }
};