
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ascTrend(const vector<int>& seq) {
    int i;
    for (i = 1; i < seq.size(); i++) {
        const auto diff = seq[i] - seq[i-1];
        const auto absDiff = abs(diff);
        if (absDiff < 1 || absDiff > 3) {
            return i;
        }

        if (diff <= 0) {
            return i;
        }
    }

    return i;
}

int descTrend(const vector<int>& seq) {
    int i;
    for (i = 1; i < seq.size(); i++) {
        const auto diff = seq[i] - seq[i-1];
        const auto absDiff = abs(diff);
        if (absDiff < 1 || absDiff > 3) {
            return i;
        }

        if (diff >= 0) {
            return i;
        }
    }

    return i;
}

int main() {
    ifstream in;
    in.open("input.in");
    int finalRes = 0;
    if (in.is_open()) {
        
        string line;
        while (getline(in, line)) {
            stringstream ss(line);
            string num;
            vector<int> seq;
            while (ss >> num) {
                seq.push_back(stoi(num));
            }

            auto res = ascTrend(seq);
            if (res == seq.size()) {
                finalRes++;
            } else {
                auto seqCopy1 = seq;
                auto seqCopy2 = seq;
                seqCopy1.erase(seqCopy1.begin() + res);
                seqCopy2.erase(seqCopy2.begin() + res - 1);
                
                if (ascTrend(seqCopy1) == seqCopy1.size()) {
                    finalRes++;
                } else if (ascTrend(seqCopy2) == seqCopy2.size()) {
                    finalRes++;
                }
            }

            res = descTrend(seq);
            if (res == seq.size()) {
                finalRes++;
            } else {
                auto seqCopy1 = seq;
                auto seqCopy2 = seq;
                seqCopy1.erase(seqCopy1.begin() + res);
                seqCopy2.erase(seqCopy2.begin() + res - 1);
                
                if (descTrend(seqCopy1) == seqCopy1.size()) {
                    finalRes++;
                } else if (descTrend(seqCopy2) == seqCopy2.size()) {
                    finalRes++;
                }
            }
        }

        in.close();
    }

    cout << finalRes << endl;

    return 0;
}