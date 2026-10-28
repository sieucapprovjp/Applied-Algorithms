//
// Created by htran on 10/19/2026.
//
#include <iostream>
#include <vector>
using namespace std;

vector<long long> a, temp;
long long mergeAndCount(int left, int mid, int right) {
    int i =left;
    int j =mid+1;
    int k =left;
    long long count = 0;
    while (i<=mid && j<=right) {
        if (a[i]<=a[j]) {
            temp[k++]=a[i++];
        } else {
            count += mid - i + 1;
            temp[k++]=a[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= right) {
        temp[k++] = a[j++];
    }
    for (int p = left; p <= right; ++p) {
        a[p] = temp[p];
    }
    return count;
}

long long mergeSort(int left, int right) {
    if (left >= right) {
        return 0;
    }
    int mid = left + (right - left) / 2;
    long long count = 0;
    count += mergeSort(left, mid);
    count += mergeSort(mid + 1, right);
    count += mergeAndCount(left, mid, right);
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    a.resize(n);
    temp.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    const long long MOD = 1000000007LL;
    cout << mergeSort(0,n-1) % MOD << '\n';
    return 0;
}