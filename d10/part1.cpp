
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

int bfs(const vector<string>& mat, const vector< pair<int, int > >& trailHeads, const vector< pair<int, int > >& ends) {
    int res = 0;
    for (const auto trailHead : trailHeads) {
        queue< pair<int, int > > q;
        vector< vector<bool> > vis(mat.size(), vector<bool>(mat.size(), false));

        q.push({trailHead.first, trailHead.second});
        vis[trailHead.first][trailHead.second] = true;

        while (!q.empty()) {
            const auto curr = q.front(); q.pop();
            const auto x = curr.first;
            const auto y = curr.second;
            for (int i = 0; i < 4; i++) {
                const auto nx = x + dx[i];
                const auto ny = y + dy[i];

                if (outOfBounds(nx, ny, mat.size()) || vis[nx][ny] || mat[nx][ny] - mat[x][y] != 1) continue;

                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        for (const auto el : ends) {
            if (vis[el.first][el.second]) {
                res++;
            }
        }
    }

    return res;
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
        const auto ends = findPositions(mat, '9');

        const auto res = bfs(mat, trailHeads, ends);
        cout << res << endl;
    }



    return 0;
}