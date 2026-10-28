//
// Created by htran on 10/19/2026.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<long long>& a,int C,long long d) {
    int count = 1;
    long long last = a[0];
    for (int i = 1;i<(int)a.size();++i) {
        if (a[i]-last>=d) {
            ++count;
            last = a[i];
            if (count == C) {
                return true;
            }
        }
    }
    return false;
}

long long solve(vector<long long>& a, int C) {
    sort(a.begin(), a.end());
    long long left = 0;
    long long right = (a.back()-a.front())/(C - 1);
    long long answer = 0;
    while (left <= right) {
        long long mid = left +(right-left)/2;
        if (check(a, C, mid)) {
            answer = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, C;
        cin >> N >> C;
        vector<long long> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        cout << solve(a, C) << '\n';
    }
    return 0;
}