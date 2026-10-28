#include <bits/stdc++.h>
using namespace std;

int n;
static int c[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    // 1. Nearest Neighbor
    vector<int> t;
    vector<bool> vis(n, false);
    int cur = 0;
    vis[0] = true;
    t.push_back(0);
    for (int step = 1; step < n; step++) {
        int best = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && (best == -1 || c[cur][j] < c[cur][best]))
                best = j;
        }
        vis[best] = true;
        t.push_back(best);
        cur = best;
    }
    // 2. 2-opt
    auto start = chrono::steady_clock::now();
    bool improved = true;
    while (improved) {
        improved = false;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 2; j < n; j++) {
                if (i == 0 && j == n - 1) continue;
                int a = t[i], b = t[i + 1];
                int cc = t[j], d = t[(j + 1) % n];
                long long delta = (long long)c[a][cc] + c[b][d]
                                - c[a][b] - c[cc][d];
                if (delta < 0) {
                    reverse(t.begin() + i + 1, t.begin() + j + 1);
                    improved = true;
                }
            }
        }
        double el = chrono::duration<double>(
            chrono::steady_clock::now() - start).count();
        if (el > 1.5) break;
    }
    cout << n << "\n";
    for (int i = 0; i < n; i++) cout << t[i] + 1 << " \n"[i == n - 1];
    return 0;
}