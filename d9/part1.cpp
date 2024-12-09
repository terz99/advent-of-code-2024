
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll FREE_SPACE = -1;

vector<ll> constructBlock(const string& line) {
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

    return block;
}

void processBlock(vector<ll>& block) {
    int i = 0, j = block.size() - 1;

    while(i < j) {
        if (block[i] != FREE_SPACE) {
            i++;
        } else {
            while (block[j] == FREE_SPACE) {
                j--;
            }
            block[i] = block[j];
            block[j] = FREE_SPACE;
            i++;
            j--;
        }
    }
}

int main() {
    ifstream in;
    // in.open("test_input.in");
    in.open("input.in");
    if (in.is_open()) {
        string line;
        in >> line;

        auto block = constructBlock(line);
        processBlock(block);
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