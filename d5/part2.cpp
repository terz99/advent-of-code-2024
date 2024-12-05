
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< vector<bool> > rules(100, vector<bool>(100, false));

vector<int> splitString(const string& str) {
    vector<int> result;
    stringstream ss(str); // Create a string stream
    string item;

    while (getline(ss, item, ',')) {
        result.push_back(stoi(item)); // Add each token to the result
    }

    return result;
}

int cmp(const int& a, const int& b) {
    if (rules[a][b]) {
        return -1;
    }

    if (rules[b][a]) {
        return 1;
    }

    return 0;
}

bool isOrdered(const vector<int>& update) {
    for (int i = 0; i < update.size(); i++) {
        for (int j = i+1; j < update.size(); j++) {
            if (cmp(update[i], update[j]) > 0) {
                return false;
            }
        }
        
    }
    return true;
}

int main() {
    ifstream in;
    in.open("input.in");
    int res = 0;
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            if (line.empty()) {
                break;
            }
            int a = (int)(line[0] - '0') * 10 + (int)(line[1] - '0');
            int b = (int)(line[3] - '0') * 10 + (int)(line[4] - '0');
            rules[a][b] = true;
        }

        while (getline(in, line)) {
            auto update = splitString(line);
            if (!isOrdered(update)) {
                // int arrCopy[update.size()];
                // for (int i = 0; i < update.size(); i++) {
                //     arrCopy[i] = update[i];
                // }
                // typedef int (*comp_fn_t)(const void *, const void *);
                // qsort(arrCopy, update.size(), sizeof(int), (comp_fn_t)cmp);
                // res += arrCopy[update.size() / 2];
                sort(update.begin(), update.end(), cmp);
                res += update[update.size() / 2];
            }
        }

        in.close();
    }

    cout << res << endl;

    return 0;
}