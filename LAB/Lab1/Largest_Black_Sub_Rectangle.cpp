//
// Created by htran on 9/21/2026.
//
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> computeRight(vector<int>&h,int m) {
    vector<int> R(m+2);
    stack<int> S;
    for (int i=1;i <= m+1; ++i) {
        while (!S.empty() && h[i] <h[S.top()]) {
            int j= S.top();
            S.pop();
            R[j]= i;
        }
        S.push(i);
    }
    return R;
}

vector<int> computeLeft(vector<int> &h,int m) {
    vector<int> L(m+2);
    stack<int> S;
    for (int i=m;i >=0;--i) {
        while (!S.empty() && h[i] < h[S.top()]) {
            int j = S.top();
            S.pop();
            L[j] = i;
        }
        S.push(i);
    }
    return L;
}

int maxHistogram(vector<int>&h, int m) {
    vector<int> R = computeRight(h,m);
    vector<int> L = computeLeft(h,m);
    int maxArea = 0;
    for (int i=1;i<=m; ++i) {
        int width = R[i] - L[i] -1;
        int area = h[i] * width;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    if (!(cin >> n >>m)) return 0;
    vector<int>h (m+2,0);
    h[0] = -1; h[m+1] = -1;
    int res =0;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            int val;
            cin >> val;
            if (val ==1) h[j] ++;
            else h[j] =0;
        }
        res = max(res,maxHistogram(h,m));
    }
    cout << res;
    return 0;
}

