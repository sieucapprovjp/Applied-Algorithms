//
// Created by htran on 10/19/2026.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment {
    long long begin, end;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (int i=0;i<n;++i) {
        cin >> segments[i].begin >> segments[i].end;
    }
    sort(segments.begin(),segments.end(),[](const Segment& a, const Segment& b) {
             return a.end < b.end;
         });
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int answer=1;
    long long last = segments[0].end;
    for (int i=1;i<n;++i) {
        if (segments[i].begin > last) {
            ++answer;
            last = segments[i].end;
        }
    }
    cout<<answer<< "\n";
    return 0;
};