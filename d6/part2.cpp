
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const char GUARD = '^';
const char REACTOR = '#';
const char FREE_SPACE = '.';

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct Position {
    int x, y, d;
    Position(){}   
    Position(const int x, const int y, const int d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }

    bool operator<(const Position& other) const {
        if (this->x == other.x) {
            if (this->y == other.y) {
                return this->d < other.d;
            }
            return this->y < other.y;
        }
        return this->x < other.x;
    }
};

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

int simulate(const vector<string>& mat, int sx, int sy) {
    set<Position> vis;
    auto x = sx;
    auto y = sy;
    int di = 0;
    while(true) {
        Position currPos = Position(x, y, di);
        if (vis.find(currPos) != vis.end()) {
            return 1;
        }
        vis.insert(currPos);
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

    return 0;
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

        n = mat.size();
        const auto startingPosPair = getStartingPosition(mat);
        const auto sx = startingPosPair.first;
        const auto sy = startingPosPair.second;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == FREE_SPACE) {
                    mat[i][j] = REACTOR;
                    res += simulate(mat, sx, sy);
                    mat[i][j] = FREE_SPACE;
                }
            }
        }
        in.close();
    }

    cout << res << endl;


    return 0;
}