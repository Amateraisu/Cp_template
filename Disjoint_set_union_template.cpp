struct DSU {
    // parent[i] = parent of i; parent of root = root itself
    // size[i]   = approximate size (or rank) of the tree with root i
    vector<int> parent, size;

    // constructor: initializes DSU for [0..n-1]
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;   // each node is initially its own parent (root)
        }
    }
    int findSet(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = findSet(parent[v]);
    }

    int sz(int n) const {
        return size[n];
    }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) {
            return false; // same set already
        }
        if (size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};
