
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ull MULTIPLIER = 2024;

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

int main() {
    ifstream in;
    // in.open("test_input.in");
    in.open("input.in");
    if (in.is_open()) {
        ull input;
        vector<ull> arr;
        while (in >> input) {
            arr.push_back(input);
        }

        // for (int i = 0; i < arr.size(); i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        for (int _ = 0; _ < 25; _++) {
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] == 0) {
                    arr[i] = 1;
                } else if (isEvenDigits(arr[i])) {
                    const auto numbers = splitNumber(arr[i]);
                    arr[i] = numbers.first;
                    arr.insert(arr.begin() + i + 1, numbers.second);
                    // cout << arr[i] << " ";
                    i++;
                } else {
                    arr[i] = arr[i]*MULTIPLIER;
                }
                // cout << arr[i] << " ";
            }
            // cout << endl;
        }

        cout << arr.size() << endl;
    }



    return 0;
}