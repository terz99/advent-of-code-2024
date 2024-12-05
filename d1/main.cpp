#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ifstream in;
    in.open("input.in");
    vector<ll> a, b;
    if (in.is_open()) {
        
        ll tmp;
        while (in >> tmp) {
            a.push_back(tmp);
            cout << tmp << endl;
            b.push_back(tmp);
        }

        in.close();
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += abs(a[i] - b[i]);
    }

    cout << sum << endl;

    return 0;
}