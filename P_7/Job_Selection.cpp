/* Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.
Select and schedule a subset of jobs of J such that the total profits is maximal.
Input
Line 1: contains a positive integer n (1 <= n <= 10^5)
Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 10^5)
Output
Write to total profits obtained from the subset of jobs found. */

#include <bits/stdc++.h>
using namespace std;

int parentSlot[100005];

int findSlot(int x) {
    if (parentSlot[x] == x) return x;
    return parentSlot[x] = findSlot(parentSlot[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> jobs(n); // {profit, deadline}
    int maxD = 0;
    for (int i = 0; i < n; i++) {
        int d, p;
        cin >> d >> p;
        jobs[i] = {p, d};
        maxD = max(maxD, d);
    }

    sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());

    for (int i = 0; i <= maxD; i++) parentSlot[i] = i;

    long long total = 0;
    for (auto &job : jobs) {
        int p = job.first, d = job.second;
        int slot = findSlot(d);
        if (slot > 0) {
            total += p;
            parentSlot[slot] = slot - 1;
        }
    }

    cout << total << endl;
    return 0;
}
