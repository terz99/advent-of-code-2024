
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

bool outOfBounds(const int x, const int y, const int size) {
    return x < 0 || x >= size || y < 0 || y >= size;
}

void floodRegion(
    const vector<string>& mat, 
    vector< vector<int> >& regions, 
    unordered_map<int, int>& perimeters, 
    unordered_map<int, int>& areas, 
    const int sx, 
    const int sy, 
    const char crop, 
    const int regionNum
) {
    unordered_map<pair<int, int>, set<pair<int, int>>, pair_hash> sides;
    queue< pair<int, int> > q;
    q.push({sx, sy});
    regions[sx][sy] = regionNum;
    areas[regionNum]++;

    while (!q.empty()) {
        const auto x = q.front().first;
        const auto y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            const auto nx = x + dx[i];
            const auto ny = y + dy[i];

            if (outOfBounds(nx, ny, mat.size()) || mat[nx][ny] != crop) {
                sides[{dx[i], dy[i]}].insert({x, y});
                continue;
            }

            if (regions[nx][ny] != -1) {
                continue;
            }

            regions[nx][ny] = regionNum;
            areas[regionNum]++;
            q.push({nx, ny});
        }
    }

    for (const auto side : sides) {
        set<pair<int, int>> seen;
        const auto coordinatesSet = side.second;
        for (const auto coordinates : coordinatesSet) {
            const auto x = coordinates.first;
            const auto y = coordinates.second;

            if (seen.find({x, y}) != seen.end()) continue;

            perimeters[regionNum]++;
            queue<pair<int, int>> q;
            q.push({x, y});

            while (!q.empty()) {
                const auto currX = q.front().first;
                const auto currY = q.front().second;
                q.pop();

                if (seen.find({currX, currY}) != seen.end()) continue;

                seen.insert({currX, currY});
                for (int i = 0; i < 4; i++) {
                    const auto nx = currX + dx[i];
                    const auto ny = currY + dy[i];
                    if (coordinatesSet.find({nx, ny}) != coordinatesSet.end()) {
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
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

        vector< vector<int> > regions(mat.size(), vector<int>(mat.size(), -1));
        unordered_map<int, int> perimeters, areas;
        int numOfRegions = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat.size(); j++) {
                if (regions[i][j] == -1) {
                    floodRegion(mat, regions, perimeters, areas, i, j, mat[i][j], numOfRegions);
                    numOfRegions++;
                }
            }
        }

        ull res = 0;
        for (int i = 0; i < numOfRegions; i++) {
            res += (ull) perimeters[i] * (ull) areas[i];
        }

        cout << res << endl;
    }



    return 0;
}