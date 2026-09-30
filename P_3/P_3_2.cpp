#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = -1e9;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void build(const vector<int>& a, int id, int l, int r) {
        if (l == r) {
            tree[id] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * id, l, mid);
        build(a, 2 * id + 1, mid + 1, r);
        tree[id] = max(tree[2 * id], tree[2 * id + 1]);
    }

    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            tree[id] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * id, l, mid, pos, val);
        else
            update(2 * id + 1, mid + 1, r, pos, val);
        tree[id] = max(tree[2 * id], tree[2 * id + 1]);
    }

    int query(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return INF;
        if (u <= l && r <= v) return tree[id];

        int mid = (l + r) / 2;
        return max(query(2 * id, l, mid, u, v),
                   query(2 * id + 1, mid + 1, r, u, v));
    }

public:
    SegmentTree(const vector<int>& a, int size) : n(size) {
        tree.assign(4 * n + 5, INF);
        build(a, 1, 1, n);
    }

    void update(int pos, int val) {
        update(1, 1, n, pos, val);
    }

    int getMax(int u, int v) {
        return query(1, 1, n, u, v);
    }
};

int main() {
    // Tối ưu I/O cho lượng truy vấn lớn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    SegmentTree st(a, n);

    int m;
    cin >> m;

    while (m--) {
        string type;
        cin >> type;
        if (type == "update") {
            int i, v;
            cin >> i >> v;
            st.update(i, v);
        } else if (type == "get-max") {
            int i, j;
            cin >> i >> j;
            cout << st.getMax(i, j) << "\n";
        }
    }

    return 0;
}