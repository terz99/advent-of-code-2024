
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int d[] = {-1, 0, 1};

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
                if (mat[i][j] == 'A') {
                    string word1 = "";
                    string word2 = "";
                    for (int k = 0; k < 3; k++) {
                        const auto nx = i + d[k];
                        const auto ny = j + d[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            break;
                        }
                        word1 += mat[nx][ny];
                    }

                    for (int k = 0; k < 3; k++) {
                        const auto nx = i + d[k];
                        const auto ny = j - d[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            break;
                        }
                        word2 += mat[nx][ny];
                    }

                    if ((word1 == "MAS" || word1 == "SAM") && (word2 == "MAS" || word2 == "SAM")) {
                        res++;
                    }
                }
            }
        }

        in.close();
    }

    cout << res << endl;

    return 0;
}