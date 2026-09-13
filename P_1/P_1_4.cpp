#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

// Biến lưu trữ dữ liệu
int total_transactions = 0;
long long total_money = 0;
set<string> accounts;
map<string, long long> money_from;
map<string, vector<string>> adj; // Đồ thị có hướng lưu các giao dịch

// Hàm DFS kiểm tra chu trình độ dài k
// current: đỉnh hiện tại
// start_node: đỉnh gốc bắt đầu chu trình
// depth: số đỉnh đã đi qua
// k: độ dài chu trình cần tìm
// visited: tập các đỉnh đã thăm trên đường đi hiện tại
bool dfs_cycle(const string &current, const string &start_node, int depth, int k, set<string> &visited) {
    // Khi đã đi qua đúng k đỉnh phân biệt
    if (depth == k) {
        // Kiểm tra xem từ đỉnh thứ k có cạnh quay về đỉnh gốc không
        if (adj.count(current)) {
            for (const string &neighbor : adj[current]) {
                if (neighbor == start_node) return true;
            }
        }
        return false;
    }

    // Nếu chưa đủ k đỉnh, duyệt tiếp các đỉnh kề
    if (adj.count(current)) {
        for (const string &next_node : adj[current]) {
            // Chu trình yêu cầu các đỉnh a_1, a_2, ..., a_k phải phân biệt (distinct)
            if (visited.find(next_node) == visited.end()) {
                visited.insert(next_node);
                if (dfs_cycle(next_node, start_node, depth + 1, k, visited)) {
                    return true;
                }
                visited.erase(next_node); // Backtrack
            }
        }
    }
    return false;
}

int main() {
    // Tối ưu I/O bắt buộc khi đọc nhiều dòng
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ==========================================
    // KHỐI 1: ĐỌC DỮ LIỆU CÁC GIAO DỊCH
    // ==========================================
    string from_acc;
    while (cin >> from_acc) {
        if (from_acc == "#") break;

        string to_acc, time_point, atm;
        long long money;
        cin >> to_acc >> money >> time_point >> atm;

        // Cập nhật thống kê
        total_transactions++;
        total_money += money;

        accounts.insert(from_acc);
        accounts.insert(to_acc);

        money_from[from_acc] += money;
        adj[from_acc].push_back(to_acc);
    }

    // ==========================================
    // KHỐI 2: XỬ LÝ CÁC TRUY VẤN (QUERIES)
    // ==========================================
    string query;
    while (cin >> query) {
        if (query == "#") break;

        if (query == "?number_transactions") {
            cout << total_transactions << "\n";
        }
        else if (query == "?total_money_transaction") {
            cout << total_money << "\n";
        }
        else if (query == "?list_sorted_accounts") {
            // Set đã tự sắp xếp theo từ điển
            bool first = true;
            for (const string &acc : accounts) {
                if (!first) cout << " ";
                cout << acc;
                first = false;
            }
            cout << "\n";
        }
        else if (query == "?total_money_transaction_from") {
            string acc;
            cin >> acc;
            // Dùng map để tra cứu O(log N)
            if (money_from.count(acc)) {
                cout << money_from[acc] << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
        else if (query == "?inspect_cycle") {
            string acc;
            int k;
            cin >> acc >> k;

            // Nếu tài khoản không tồn tại hoặc k <= 1 thì không thể tạo chu trình
            if (accounts.find(acc) == accounts.end() || k <= 1) {
                cout << 0 << "\n";
                continue;
            }

            set<string> visited;
            visited.insert(acc);

            if (dfs_cycle(acc, acc, 1, k, visited)) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }

    return 0;
}