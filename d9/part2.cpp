
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll FREE_SPACE = -1;

vector<ll> processBlock(const string& line) {
    vector<ll> block;
    ll idx = 0;
    for (int i = 0; i < line.length(); i++) {
        auto blockLen = (int) (line[i] - '0');
        while (blockLen--) {
            if (i % 2) {
                block.push_back(FREE_SPACE);
            } else {
                block.push_back(idx);
            }
        }

        if (i % 2 == 0) {
            idx++;
        }
    }
    idx--;

    int i, j = block.size() - 1, count_j, count_i, tmp_i;

    while (idx > 1) {
        i = 0;
        while (block[j] != idx) {
            j--;
        }
        count_j = 0;
        while (block[j] == idx) {
            count_j++;
            j--;
        }

        while (i < j) {
            if (block[i] == FREE_SPACE) {
                count_i = 0;
                tmp_i = i;
                while (block[tmp_i] == FREE_SPACE) {
                    tmp_i++;
                    count_i++;
                }

                if (count_i >= count_j) {
                    break;
                }
            }
            i++;
        }

        if (i < j) {
            for (int k = 0; k < count_j; k++) {
                block[i++] = idx;
                block[++j] = FREE_SPACE;
            }
        }
        idx--;
    }

    return block;
}

int main() {
    ifstream in;
    // in.open("test_input.in");
    in.open("input.in");
    if (in.is_open()) {
        string line;
        in >> line;

        const auto block = processBlock(line);
        ll res = 0;
        for (ll i = 0; i < block.size(); i++) {
            if (block[i] == FREE_SPACE) {
                continue;
            }
            res += (i * block[i]);
        }

        cout << res << endl;
    }



    return 0;
}