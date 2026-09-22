//
// Created by htran on 9/22/2026.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Tối ưu tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long M;
    if (!(cin >> n >> M)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sắp xếp mảng tăng dần: O(n log n)
    sort(a.begin(), a.end());

    int left = 0;
    int right = n - 1;
    long long count = 0;

    // Kỹ thuật Two Pointers
    while (left < right) {
        long long sum = a[left] + a[right];
        if (sum == M) {
            count++;
            left++;
            right--;
        } else if (sum < M) {
            left++;
        } else {
            right--;
        }
    }

    cout << count << "\n";

    return 0;
}