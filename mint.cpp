namespace modint {

    template<typename T> 
    T pow(T a,long long b) {
        T res = 1;
        while(b) {
            if(b & 1) res *= a;
            b >>= 1; a *= a;
        } 
        return res;
    }

    const int mod = 1e9 + 7;
    //const int mod = 998244353;

    struct Mint {

        int val;

        Mint() : val(0) {}

        int operator() () { return val; }

        Mint(int a) {
            a %= mod;
            if(a < 0) a += mod;
            val = a;
        }

        Mint& operator+=(Mint a) {
            val += a.val;
            if(val >= mod) val -= mod;
            return *this;
        }

        Mint& operator-=(Mint a) {
            val -= a.val;
            if(val < 0) val += mod;
            if(val >= mod) val -= mod;
            return *this;
        }

        Mint& operator*=(Mint a) {
            val = 1ll * val * a.val % mod;
            return *this;
        }

        Mint inv() { return pow(*this,mod-2); }

        Mint& operator/=(Mint a) {
            val = 1ll * val * a.inv().val % mod;
            return *this;
        }

        bool operator==(Mint a) const { return val == a.val; }
        bool operator!=(Mint a) const { return val != a.val; }
        bool operator<(Mint a) const { return val < a.val; }
        bool operator>(Mint a) const { return val > a.val; }
        bool operator<=(Mint a) const { return val <= a.val; }
        bool operator>=(Mint a) const { return val >= a.val; }

    };

    Mint operator+(Mint a,Mint b) { return a += b; }

    Mint operator-(Mint a,Mint b) { return a -= b; }

    Mint operator*(Mint a,Mint b) { return a *= b; }

    Mint operator/(Mint a,Mint b) { return a /= b; }

    ostream& operator<<(std::ostream& os,Mint a) { return os<<a.val; }

    istream& operator>>(std::istream& is,Mint &a) {
        long long x;
        is>>x;
        a = Mint(x);
        return is;
    }

};

using namespace modint;
