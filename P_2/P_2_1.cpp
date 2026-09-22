//
// Created by htran on 9/22/2026.
//

/* The revenue of a shop on day i is a[i] (i = 1, 2, . . ., n).  Given a threshold D (positive integer), compute the nunmber Q of consecutive days in which the total revenue is geater or equal to D.
Input
Line 1: contains 2 positive integers n and D (1 <= n <= 1000, 1 <= D <= 1000)
Line 2: contains n integers a[1], a[2], . . ., a[n] (1 <= a[i] <= 100)

Output
Write the value Q

Example
Input
5 12
1 6 4 2 9

//Output 5 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, D;
    if (!(cin >> n >> D)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += a[j];
            if (current_sum >= D) {
                count++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}
