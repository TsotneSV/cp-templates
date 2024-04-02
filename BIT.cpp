struct BIT {
    int n; vector<long long> S;

    void update(int pos,int add) {
        for(pos;pos<=n;pos+=pos&-pos) S[pos]+=add;
    }

    ll sum(int pos) {
        ll ret=0;
        for(pos;pos>0;pos-=pos&-pos) ret += S[pos];
        return ret;
    }

    ll query(int l,int r) {
        return sum(r) - sum(l-1);
    }

    BIT(vector<int> v) {
        n = v.size();
        S = vector<long long>(n+1,0);
        for(int i=0;i<n;i++) update(i+1,v[i]);
    }
};
