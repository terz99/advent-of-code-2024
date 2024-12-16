
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<ull, int, int, int> Node;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

tuple<int, int, int, int> getStartAndEndPoints(const vector<string>& mat) {
    int sx, sy, ex, ey;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (mat[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    return {sx, sy, ex, ey};
}

ull getAddition(const int a, const int b) {
    if (a == b) {
        return 0ull;
    }

    if (abs(a - b) == 2) {
        return 2000ull;
    }

    return 1000ull;
}

ull dijkstra(const vector<string>& mat, const int sx, const int sy, const int ex, const int ey) {
    vector< vector<ull> > dist(mat.size(), vector<ull>(mat[0].size(), (ull) INT_MAX));
    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push(Node(0ull, sx, sy, 0));
    dist[sx][sy] = 0ull;

    while (!q.empty()) {
        const auto [_, x, y, dir] = q.top(); q.pop();
        
        for (int i = 0; i < 4; i++) {
            const auto add = getAddition(i, dir);

            const auto nx = dx[i] + x;
            const auto ny = dy[i] + y;

            if (mat[nx][ny] == '#') continue;

            if (dist[nx][ny] > dist[x][y] + add + 1ull) {
                dist[nx][ny] = dist[x][y] + add + 1ull;
                q.push(Node(dist[nx][ny], nx, ny, i));
            }
        }
    }

    return dist[ex][ey];
}

int main() {
    ifstream in;
    // in.open("test_input.in");
    in.open("input.in");
    if (in.is_open()) {
        string line;
        vector<string> mat;
        while (getline(in, line)) {
            mat.push_back(line);
        }
        
        const auto [sx, sy, ex, ey] = getStartAndEndPoints(mat);
        cout << dijkstra(mat, sx, sy, ex, ey) << endl;
    }



    return 0;
}