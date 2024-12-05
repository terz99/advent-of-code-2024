
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> splitString(const string& str) {
    vector<int> result;
    stringstream ss(str); // Create a string stream
    string item;

    while (getline(ss, item, ',')) {
        result.push_back(stoi(item)); // Add each token to the result
    }

    return result;
}

int main() {
    ifstream in;
    in.open("input.in");
    int res = 0;
    if (in.is_open()) {
        
        set<int> rules[100];

        string line;
        while (getline(in, line)) {
            if (line.empty()) {
                break;
            }
            int a = (int)(line[0] - '0') * 10 + (int)(line[1] - '0');
            int b = (int)(line[3] - '0') * 10 + (int)(line[4] - '0');
            rules[a].insert(b);
        }

        while (getline(in, line)) {
            bool isValid = true;
            const auto update = splitString(line);
            for (int i = update.size() - 1; i >= 0; i--) {
                const auto curr = update[i];
                for (int j = i-1; j >= 0; j--) {
                    if (rules[curr].find(update[j]) != rules[curr].end()) {
                        isValid = false;
                        break;
                    }
                }

                if (!isValid) {
                    break;
                }
            }

            if (isValid) {
                res += update[update.size() / 2];
            }
        }

        in.close();
    }

    cout << res << endl;

    return 0;
}