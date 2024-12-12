
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

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
                perimeters[regionNum]++;
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
            cout << perimeters[i] << " " << areas[i] << endl;
            res += (ull) perimeters[i] * (ull) areas[i];
        }

        cout << res << endl;
    }



    return 0;
}