#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ifstream in;
    in.open("input.in");
    unordered_map<ll, int> freq;
    vector<ll> a;
    if (in.is_open()) {
        
        ll tmp;
        while (in >> tmp) {
            a.push_back(tmp);
            in >> tmp;
            freq[tmp]++;
        }

        in.close();
    }

    ll sum = 0;
    for (const auto& num : a) {
        sum += (num * freq[num]);
    }

    cout << sum << endl;

    return 0;
}