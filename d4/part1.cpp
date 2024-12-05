
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dx[8][4] = {
    {0, 0, 0, 0},
    {0, -1, -2, -3},
    {0, -1, -2, -3},
    {0, -1, -2, -3},
    {0, 0, 0, 0},
    {0, 1, 2, 3},
    {0, 1, 2, 3},
    {0, 1, 2, 3}
};

int dy[8][4] = {
    {0, 1, 2, 3},
    {0, 1, 2, 3},
    {0, 0, 0, 0},
    {0, -1, -2, -3},
    {0, -1, -2, -3},
    {0, -1, -2, -3},
    {0, 0, 0, 0},
    {0, 1, 2, 3},
};

int main() {
    ifstream in;
    in.open("input.in");
    int res = 0;
    if (in.is_open()) {
        
        vector<string> mat;
        string line;
        while (getline(in, line)) {
            mat.push_back(line);
        }

        const auto n = mat.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 8; k++) {
                    string word = "";
                    for (int l = 0; l < 4; l++) {
                        int nx = i + dx[k][l];
                        int ny = j + dy[k][l];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            break;
                        }
                        word += mat[nx][ny];
                    }

                    if (word == "XMAS" || word == "SAMX") {
                        cout << word << endl;
                        res++;
                    }
                }
            }
        }

        in.close();
    }

    cout << res / 2 << endl;

    return 0;
}