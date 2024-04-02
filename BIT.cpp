struct HashedString {
    const ll mod = 1e9 + 7;
    const ll p = 125213;
 
    int n;
    vector<ll> pw;
    vector<ll> h;
 
    void build(string s) {
        n = (int)s.size();
        pw.resize(n + 1);
        h.resize(n + 1);
        pw[0] = 1;
        h[0] = 0;
        for (int i = 0; i < n; i += 1) {
            pw[i + 1] = (pw[i] * p) % mod;
            h[i + 1] = (h[i] * p + (s[i] - 'a' + 1)) % mod;
        }
    }
 
 
    ll get(int l, int r) {
        return ((h[r + 1] - h[l] * pw[r - l + 1]) % mod + mod) % mod;
    }
 
 
    ll rget(int l, int r) {
        return get(n - r - 1, n - l - 1);
    }
};
