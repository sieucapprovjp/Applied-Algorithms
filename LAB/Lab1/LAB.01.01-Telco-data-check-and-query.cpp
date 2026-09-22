#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int is_valid_phone_num(string phone_num) {
    if (phone_num.length() != 10)
        return 0;

    for (int i = 0; i < 10; i++) {
        if (phone_num[i] < '0' || phone_num[i] > '9')
            return 0;
    }

    return 1;
}

int duration(string from_time, string to_time) {
    int from_hour, from_minute, from_second;
    int to_hour, to_minute, to_second;

    from_hour = stoi(from_time.substr(0, 2));
    from_minute = stoi(from_time.substr(3, 2));
    from_second = stoi(from_time.substr(6, 2));

    to_hour = stoi(to_time.substr(0, 2));
    to_minute = stoi(to_time.substr(3, 2));
    to_second = stoi(to_time.substr(6, 2));

    return (to_hour * 3600 + to_minute * 60 + to_second)
         - (from_hour * 3600 + from_minute * 60 + from_second);
}

int main() {
    int all_phone_num_correct = 1;

    map<string, int> number_calls;
    int number_total_calls = 0;

    map<string, int> total_duration;

    string input_token;

    while (1) {
        cin >> input_token;

        if (input_token == "#")
            break;

        // from_number
        string from_number;
        cin >> from_number;

        if (is_valid_phone_num(from_number) == 0)
            all_phone_num_correct = 0;

        if (number_calls.find(from_number) != number_calls.end())
            number_calls[from_number]++;
        else
            number_calls[from_number] = 1;

        // to_number
        string to_number;
        cin >> to_number;

        if (is_valid_phone_num(to_number) == 0)
            all_phone_num_correct = 0;

        // date
        string date;
        cin >> date;

        // from_time
        string from_time;
        cin >> from_time;

        // to_time
        string to_time;
        cin >> to_time;

        int call_duration = duration(from_time, to_time);

        if (total_duration.find(from_number) != total_duration.end())
            total_duration[from_number] += call_duration;
        else
            total_duration[from_number] = call_duration;

        number_total_calls++;
    }

    string cmd;
    vector<string> outputs;

    while (1) {
        cin >> cmd;

        if (cmd == "#")
            break;

        if (cmd == "?check_phone_number") {
            outputs.push_back(to_string(all_phone_num_correct));
        }
        else if (cmd == "?number_calls_from") {
            string from_number;
            cin >> from_number;

            outputs.push_back(to_string(number_calls[from_number]));
        }
        else if (cmd == "?number_total_calls") {
            outputs.push_back(to_string(number_total_calls));
        }
        else if (cmd == "?count_time_calls_from") {
            string from_number;
            cin >> from_number;

            outputs.push_back(to_string(total_duration[from_number]));
        }
        else {
            break;
        }
    }

    for (int i = 0; i < outputs.size(); i++)
        cout << outputs[i] << '\n';

    return 0;
}
