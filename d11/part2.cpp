
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ull MULTIPLIER = 2024;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

unordered_map<pair<ull, ull>, ull, pair_hash> dp;

bool isEvenDigits(ull x) {
    int cnt = 0;
    while (x > 0) {
        x = x / 10;
        cnt++;
    }

    return cnt % 2 == 0;
}

pair<ull, ull> splitNumber(ull x) {
    const auto xString = to_string(x);
    const auto firstNum = xString.substr(0, xString.length() / 2);
    const auto secondNum = xString.substr(xString.length() / 2);
    return {stoull(firstNum), stoull(secondNum)};
}

ull solve(const ull x, const ull t) {
    if (dp[{x, t}]) {
        return dp[{x, t}];
    }

    if (t == 0) {
        dp[{x, t}] = 1;
        return dp[{x, t}];
    }

    if (x == 0) {
        dp[{x, t}] = solve(1, t-1);
    } else if (isEvenDigits(x)) {
        const auto numbers = splitNumber(x);
        dp[{x, t}] = solve(numbers.first, t-1) + solve(numbers.second, t-1);
    } else {
        dp[{x, t}] = solve(x*MULTIPLIER, t-1);
    }

    return dp[{x, t}];
}

int main() {
    ifstream in;
    // in.open("test_input.in");
    in.open("input.in");
    if (in.is_open()) {
        ull input;
        vector<ull> arr;
        ull res = 0;
        while (in >> input) {
            arr.push_back(input);
        }

        for (const auto el : arr) {
            res += solve(el, 75);
        }

        cout << res << endl;
    }



    return 0;
}