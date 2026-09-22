#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Tối ưu tốc độ nhập/xuất cho C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // pref[k] lưu tổng từ a[1] đến a[k]
    // Dùng long long để đảm bảo an toàn dù n * a[i] <= 10^8 (vừa int)
    vector<long long> pref(n + 1, 0);

    for (int k = 1; k <= n; ++k) {
        long long val;
        cin >> val;
        pref[k] = pref[k - 1] + val;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int i, j;
        cin >> i >> j;
        cout << (pref[j] - pref[i - 1]) << "\n";
    }

    return 0;
}