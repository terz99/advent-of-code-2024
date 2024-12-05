#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ifstream in;
    in.open("input.in");
    int res = 0;
    if (in.is_open()) {
        
        string line;
        while (getline(in, line)) {
            stringstream ss(line);
            string num;
            vector<int> seq;
            while (ss >> num) {
                seq.push_back(stoi(num));
            }

            bool isIncreasing;
            bool isValid = true;
            for (int i = 1; i < seq.size(); i++) {
                if (i == 1) {
                    isIncreasing = seq[i] > seq[i-1];
                }

                const auto diff = abs(seq[i] - seq[i-1]);
                if (diff < 1 || diff > 3) {
                    isValid = false;
                    break;
                } 

                if (isIncreasing && seq[i] <= seq[i-1]) {
                    isValid = false;
                    break;
                }

                if (!isIncreasing && seq[i] >= seq[i-1]) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                res++;
            }
        }

        in.close();
    }

    cout << res << endl;

    return 0;
}