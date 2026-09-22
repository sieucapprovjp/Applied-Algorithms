//
// Created by htran on 9/21/2026.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> computeLog(int n) {
    vector<int> lg(n+1);
    lg[1] = 0;
    for (int i=2; i<=n;++i) {
        lg[i] = lg[i/2] +1;
    }
    return lg;
}

vector<vector<int>> SparseTable (vector<int>&a,int n) {
    int MAX_LOG = 20;
    vector<vector<int>> M(n,vector<int>(MAX_LOG));
    for (int i=0;i<n;i++) {
        M[i][0] = i;
    }
    for (int j=1;(1<<j)<= n;++j) {
        for (int i=0;i+ (1<<j) -1<n;++i) {
            int left_idx = M[i][j-1];
            int right_idx = M[i + (1 << (j-1))][j-1];
            if (a[left_idx] <=  a[right_idx]) M[i][j] = left_idx;
            else M[i][j] = right_idx;
        }
    }
    return M;
}

int query(int i,int j, vector<int>&a, vector<vector<int>>& M,vector<int>& lg) {
    int len = j-i+1;
    int k = lg[len];
    int idx1 = M[i][k];
    int idx2 = M[j - (1<<k) +1][k];
    return min(a[idx1],a[idx2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];

    vector<int> lg = computeLog(n);
    vector<vector<int>> M = SparseTable(a,n);

    int m;
    cin >> m;
    int ans=0;

    for (int i=0;i<m;i++) {
        int q,k;
        cin >> q >> k;
        ans += query(q,k,a,M,lg);
    }
    cout << ans;
    return 0;
}
