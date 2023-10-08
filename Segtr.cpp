// typedef long long ll;
template<typename Node,typename Update>
struct Segtr {

    int s;
    vector<Node> tree;

    void build(int v,int tl,int tr,vector<ll> &arr) {
        if(tl == tr) {
            tree[v] = Node(arr[tl]);
        }else {
            int tm = (tl + tr)/2;
            build(2*v,tl,tm,arr); build(2*v+1,tm+1,tr,arr);
            tree[v].merge(tree[2*v],tree[2*v+1]);
        }
    }

    void update(int v,int idx,int tl,int tr,Update addend) {
        if(tl == tr) {
            addend.apply(v);
        }else {
            int tm = (tl + tr)/2;
            update(2*v,idx,tl,tm,addend); update(2*v+1,idx,tm+1,tr,addend);
            tree[v].merge(tree[2*v],tree[2*v+1]);
        }
    }

    Node query(int v,int l,int r,int tl,int tr) {
        if(l > r) return Node(0); // *
        else if(tl == l && tr == r) return tree[v];
        int tm = (tl + tr)/2;
        Node L,R,ans;
        L = query(2*v,l,min(r,tm),tl,tm); R = query(2*v+1,max(l,tm+1),r,tm+1,tr);
        ans.merge(L,R);
        return ans;
    }

    Segtr(int n,vector<ll> &arr) {
        s = n;

        tree.resize(4*n);
        build(1,0,n-1,arr);
    }

};

struct Node1 {
    ll val; // * shecvla sheidzleba

    void merge(Node1 &a,Node1 &b) {
        val = a.val + b.val; // *
    }

    Node1() : val(0) {}

    Node1(ll a) {
        val = a; 
    }

};

struct Update1 {
    ll val; // *

    Update1(ll val) {
        this->val = val;
    }

    void apply(Node1 &a) {
        a.val = val;
    }


};
