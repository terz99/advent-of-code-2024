
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const char GUARD = '^';
const char REACTOR = '#';

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

pair<int, int> getStartingPosition(const vector<string>& mat) {
    const auto n = mat.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == GUARD) {
                return {i, j};
            }
        }
    }

    return {0, 0};
}

bool outOfBounds(const int x, const int y, const int size) {
    return x < 0 || x >= size || y < 0 || y >= size;
}

int turnRight(const int di) {
    return (di + 1) % 4;
}

void simulate(vector<string>& mat, int sx, int sy) {
    auto x = sx;
    auto y = sy;
    int di = 0;
    while(!outOfBounds(x, y, mat.size())) {
        mat[x][y] = 'X';
        const auto nx = x + dx[di];
        const auto ny = y + dy[di];
        
        if (outOfBounds(nx, ny, mat.size())) {
            break;
        }

        if (mat[nx][ny] == REACTOR) {
            di = turnRight(di);
        } else {
            x = nx;
            y = ny;
        }
    }
}

int main() {
    ifstream in;
    in.open("input.in");
    vector<string> mat;
    int n, res = 0;
    if (in.is_open()) {
        
        string line;
        while(getline(in, line)) {
            mat.push_back(line);
        }

        const auto startingPosPair = getStartingPosition(mat);
        const auto sx = startingPosPair.first;
        const auto sy = startingPosPair.second;

        simulate(mat, sx, sy);
        for (const auto row : mat) {
            for (const auto pos : row) {
                if (pos == 'X') {
                    res++;
                }
                cout << pos;
            }
            cout << endl;
        }
        in.close();
    }

    cout << res << endl;


    return 0;
}