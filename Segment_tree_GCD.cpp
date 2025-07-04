template<typename T>
struct GcdSegTree {
    int n;
    vector<T> tree;
    
    GcdSegTree(int _n): n(_n) {
        tree.assign(4*n, T{0});
    }
    
    // build from initial array a[0..n)
    void build(const vector<T>& a) {
        build(1, 0, n-1, a);
    }
    
    // point update: set a[idx] = val
    void update(int idx, T val) {
        update(1, 0, n-1, idx, val);
    }
    
    // query gcd on [l..r]
    T query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
    
private:
    void build(int node, int L, int R, const vector<T>& a) {
        if (L == R) {
            tree[node] = a[L];
        } else {
            int mid = (L + R) >> 1;
            build(node<<1,  L,    mid, a);
            build(node<<1|1, mid+1, R,   a);
            tree[node] = std::gcd(tree[node<<1], tree[node<<1|1]);
        }
    }

    void update(int node, int L, int R, int idx, T val) {
        if (L == R) {
            tree[node] = val;
        } else {
            int mid = (L + R) >> 1;
            if (idx <= mid)
                update(node<<1, L, mid, idx, val);
            else
                update(node<<1|1, mid+1, R, idx, val);
            tree[node] = std::gcd(tree[node<<1], tree[node<<1|1]);
        }
    }

    T query(int node, int L, int R, int ql, int qr) {
        if (qr < L || R < ql) 
            return T{0};               // gcd(x,0)=x
        if (ql <= L && R <= qr) 
            return tree[node];
        int mid = (L + R) >> 1;
        T left  = query(node<<1,     L,    mid, ql, qr);
        T right = query(node<<1|1, mid+1, R,   ql, qr);
        return std::gcd(left, right);
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    GcdSegTree<int> st(n);
    st.build(a);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int idx, val;
            cin >> idx >> val;
            st.update(idx, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << "\n";
        }
    }
    return 0;
}
