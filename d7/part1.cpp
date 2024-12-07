
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// Function to trim leading whitespaces
string trim_leading(const string& str) {
    const auto start = str.find_first_not_of(" \t\n\r\f\v");
    return (start == string::npos) ? "" : str.substr(start);
}

// Function to trim trailing whitespaces
string trim_trailing(const string& str) {
    const auto end = str.find_last_not_of(" \t\n\r\f\v");
    return (end == string::npos) ? "" : str.substr(0, end + 1);
}

// Function to trim both leading and trailing whitespaces
string trim(const string& str) {
    return trim_leading(trim_trailing(str));
}

vector<string> splitString(const string& str, const char delimeter) {
    vector<string> result;
    stringstream ss(str); // Create a string stream
    string item;

    while (getline(ss, item, delimeter)) {
        result.push_back(trim(item)); // Add each token to the result
    }

    return result;
}

bool findCombinations(const vector<ull>& values, const ull endValue, const int idx, const ull currValue) {
    if (currValue == endValue && idx == values.size()) {
        return true;
    }

    if (currValue > endValue || idx >= values.size()) {
        return false;
    }

    return findCombinations(values, endValue, idx+1, currValue + values[idx]) 
        || findCombinations(values, endValue, idx+1, currValue * values[idx]);
}

int main() {
    ifstream in;
    in.open("input.in");
    ull res = 0;
    if (in.is_open()) {
        
        string line;
        while(getline(in, line)) {
            const auto split = splitString(line, ':');
            const auto endValue = stoull(split[0]);
            const auto stringValues = splitString(split[1], ' ');
            vector<ull> values;
            for (const auto el : stringValues) {
                values.push_back(stoull(el));
            }

            if (findCombinations(values, endValue, 1, values[0])) {
                res += endValue;
            }
        }

        in.close();
    }

    cout << res << endl;

    return 0;
}