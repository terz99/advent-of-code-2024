
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

vector< pair<int, int > > findPositions(const vector<string>& mat, const char pos) {
    vector< pair<int, int> > res;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++) {
            if (mat[i][j] == pos) {
                res.push_back({i, j});
            }
        }
    }

    return res;
}

bool outOfBounds(const int x, const int y, const int size) {
    return x < 0 || x >= size || y < 0 || y >= size;
}

int dfs(const vector<string>& mat, vector< vector<int> >& dp, const int x, const int y) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    if (mat[x][y] == '9') {
        dp[x][y] = 1;
        return dp[x][y];
    }

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        const auto nx = x + dx[i];
        const auto ny = y + dy[i];
        
        if (outOfBounds(nx, ny, mat.size()) || mat[nx][ny] - mat[x][y] != 1) continue;

        dp[x][y] += dfs(mat, dp, nx, ny);
    }

    return dp[x][y];
}

int main() {
    ifstream in;
    // in.open("test_input.in");
    in.open("input.in");
    vector<string> mat;
    if (in.is_open()) {
        string line;
        while(getline(in, line)) {
            mat.push_back(line);
        }

        const auto trailHeads = findPositions(mat, '0');
        vector< vector<int > > dp(mat.size(), vector<int>(mat.size(), -1));
        int res = 0;
        for (const auto trailHead : trailHeads) {
            res += dfs(mat, dp, trailHead.first, trailHead.second);
        }

        cout << res << endl;
    }



    return 0;
}