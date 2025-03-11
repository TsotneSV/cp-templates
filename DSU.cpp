struct DSU {

    vector<int> parent,SIZE;

    DSU(int n) {
        parent.resize(n + 1);
        SIZE.resize(n + 1);
        for(int i=1;i<=n;i++) {
            parent[i] = i;
            SIZE[i] = 1;
        }
    }

    int find_set(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find_set(parent[u]);
    }

    void union_sets(int u,int v) {
        u = find_set(u);
        v = find_set(v);

        if(u != v) {
            if(SIZE[u] < SIZE[v]) swap(u,v);
            SIZE[u] += SIZE[v];
            parent[v] = u;
        }
    }

};
