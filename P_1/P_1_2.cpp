//
// Created by htran on 9/12/2026.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> st;
    string cmd;

    while (cin >>  cmd) {
        if (cmd == "#") break;
        else if (cmd == "PUSH") {
            int v;
            cin >> v;
            st.push(v);

        }
        else if (cmd == "POP") {
            if (st.empty()) cout << "NULL\n";
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
    }
    return  0;
}