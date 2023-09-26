namespace modop {

    const ll MOD = 1e9+7;//998244353;

    vector<ll> fact;

    ll add(ll a,ll b) {
        return ((a % MOD) + (b % MOD))%MOD;
    }

    ll sub(ll a,ll b) {
        return ((a % MOD) - (b % MOD) + MOD)%MOD;
    }
    
    ll mult(ll a,ll b) {
        return ((a % MOD) * (b % MOD))%MOD;
    }

    ll mpow(ll a,ll b) {
        ll ret = 1;

        while(b) {
            if(b&1) {
                ret = mult(ret,a);
            } b/=2;
            a = mult(a,a);
        } return ret;
    }

    ll modInv(ll a) {
        return mpow(a,MOD-2);
    }

    ll div(ll a,ll b) {
        return mult(a,modInv(b));
    }

    void set_mod(ll a) {
        MOD = a;
    }

    void gen_factorial(ll n) {
        fact.resize(n + 1); fact[0] = 1;

        for(ll i=1;i<=n;i++) {
            fact[i] = mult(fact[i-1],i);
        }
    }

    ll nCr(ll n,ll r) {

        if(r > n || r < 0) return 0;

        ll ret = 1;

        for(ll i=1;i<=r;i++) {
            ret = mult(ret,div(n-r+i,i));
        } return ret;
    }


};

using namespace modop;
