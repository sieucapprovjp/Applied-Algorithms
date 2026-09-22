//
// Created by htran on 9/22/2026.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long Q;
    if (!(cin >> n >> Q)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int left = 0;
    long long current_sum = 0;
    int max_len = 0;

    for (int right = 0; right < n; ++right) {
        current_sum += a[right];
        while (current_sum > Q && left <= right) {
            current_sum -= a[left];
            left++;
        }
        if (current_sum <= Q && left <= right) {
            max_len = max(max_len, right - left + 1);
        }
    }
    if (max_len == 0) {
        cout << -1 << "\n";
    } else {
        cout << max_len << "\n";
    }

    return 0;
}