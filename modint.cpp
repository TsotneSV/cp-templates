namespace modint {

    ll mod = 1e9+7;
   // ll mod = 998244353;

    vector<ll> fact,ifact;

    ll madd(ll a,ll b) {
        return ((a % mod) + (b % mod))%mod;
    }

    ll msub(ll a,ll b) {
        return ((a - b)%mod + mod)%mod;
    }
    
    ll mmul(ll a,ll b) {
        return ((a % mod) * (b % mod))%mod;
    }

    ll mpow(ll a,ll b) {
        ll ret = 1;

        while(b) {
            if(b&1) {
                ret = mmul(ret,a);
            } b/=2;
            a = mmul(a,a);
        } return ret;
    }

    ll minv(ll a) {
        return mpow(a,mod-2);
    }

    ll mdiv(ll a,ll b) {
        return mmul(a,minv(b));
    }

    void set_mod(ll a) {
        mod = a;
    }

    void gen_factorial(ll n=1e6+5) {
        fact.resize(n + 1); ifact.resize(n+1); fact[0] = ifact[0] = 1;

        for(ll i=1;i<=n;i++) {
            fact[i] = mmul(fact[i-1],i);
            ifact[i] = minv(fact[i]);
        }
    }

    ll nCr(ll n,ll r) {

        if(r > n || r < 0) return 0;

        return mmul(fact[n],mmul(ifact[r],ifact[n-r]));
    }

    ll nPr(ll n,ll r) {
        if(r > n || r < 0) return 0;

        return mdiv(fact[n],fact[n-r]); 
    }


};

using namespace modint;
