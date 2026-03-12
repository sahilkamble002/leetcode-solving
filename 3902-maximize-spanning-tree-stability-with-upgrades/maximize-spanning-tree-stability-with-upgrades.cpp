class Solution {
public:


    class DSU{
    public:
        vector<int> parent, rankv;

        DSU(int n){
            parent.resize(n);
            rankv.resize(n,0);
            for(int i=0;i<n;i++) parent[i]=i;
        }

        int find(int x){
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        }

        bool unite(int a,int b){
            a=find(a);
            b=find(b);

            if(a==b) return false;

            if(rankv[a] < rankv[b]) swap(a,b);

            parent[b]=a;

            if(rankv[a]==rankv[b])
                rankv[a]++;

            return true;
        }
    };

bool can(int n, vector<vector<int>>& edges, int k, int X){

    DSU dsu(n);
    int used = 0;

    vector<pair<int,int>> freeEdges;
    vector<pair<int,int>> upgradeEdges;

    for(auto &e: edges){
        int u=e[0], v=e[1], s=e[2], must=e[3];

        if(must){
            if(s < X) return false;

            if(!dsu.unite(u,v))
                return false;

            used++;
        }
    }

    for(auto &e: edges){
        int u=e[0], v=e[1], s=e[2], must=e[3];

        if(must) continue;

        if(s >= X)
            freeEdges.push_back({u,v});
        else if(2*s >= X)
            upgradeEdges.push_back({u,v});
    }

    for(auto &e: freeEdges){
        if(dsu.unite(e.first,e.second))
            used++;
    }

    int upgrades = 0;

    for(auto &e: upgradeEdges){
        if(dsu.unite(e.first,e.second)){
            used++;
            upgrades++;
            if(upgrades > k) return false;
        }
    }

    return used == n-1;
}
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int lo = 0, hi = 0;

    for(auto &e: edges)
        hi = max(hi, e[2] * 2);

    int ans = -1;

    while(lo <= hi){

        int mid = (lo + hi) / 2;

        if(can(n, edges, k, mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    return ans;
    }
};