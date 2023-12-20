struct BIT {
    int n; vi S;

    void update(int pos,int add) {
        for(pos;pos<=n;pos+=pos&-pos) S[pos]+=add;
    }

    int sum(int pos) {
        int ret=0;
        for(pos;pos>0;pos-=pos&-pos) ret += S[pos];
        return ret;
    }

    int query(int l,int r) {
        return sum(r) - sum(l-1);
    }

    BIT(vi v) {
        n = v.size();
        S = vi(n+1,0);
        for(int i=0;i<n;i++) update(i+1,v[i]);
    }
};
