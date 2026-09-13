//
// Created by htran on 9/12/2026.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios_base:: sync_with_stdio();
    cin.tie(NULL);

    queue<int> st;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "#") break;
        else if (cmd == "PUSH") {
            int u;
            cin >> u;
            st.push(u);
        }
        else if (cmd == "POP") {
            if (st.empty()) cout << "NULL\n";
            else {
                cout << st.front() << "\n";
                st.pop();
            }
        }
    }
    return 0;
}