//
// Created by htran on 9/22/2026.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Tối ưu hóa tốc độ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Khởi tạo mảng tiền tố (n + 1) x (m + 1) với chỉ số bắt đầu từ 1
    vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long val;
            cin >> val;
            pref[i][j] = val + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    int Q;
    if (cin >> Q) {
        while (Q--) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;

            long long ans = pref[r2][c2]
                          - pref[r1 - 1][c2]
                          - pref[r2][c1 - 1]
                          + pref[r1 - 1][c1 - 1];

            cout << ans << "\n";
        }
    }

    return 0;
}