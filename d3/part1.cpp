
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ifstream in;
    in.open("input.in");
    ll res = 0;
    if (in.is_open()) {
        
        regex pattern("^mul\\((\\d{1,3}),(\\d{1,3})\\)$");
        string memory = "", line;
        while (getline(in, line)) {
            memory += line;
        }
        memory.erase(remove(memory.begin(), memory.end(), '\n'), memory.end());
        for (int i = 0; i < memory.length(); i++) {
            auto substr = memory.substr(i, 3);
            if (substr == "mul") {
                for (int j = 8; j <= 12; j++) {
                    substr = memory.substr(i, j);
                    if (regex_match(substr, pattern)) {
                        ll a = 0, b = 0;
                        int k;
                        for (k = i+4; memory[k] != ','; k++) {
                            a = a*10 + (int) (memory[k] - '0');
                        }
                        k++;
                        for (; memory[k] != ')'; k++) {
                            b = b*10 + (int) (memory[k] - '0');
                        }
                        cout << substr << endl;
                        cout << a << " " << b << endl;
                        res += (a*b);
                    }
                }
            }
        }

        in.close();
    }

    cout << res << endl;

    return 0;
}