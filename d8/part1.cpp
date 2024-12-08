
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

set< pair<int, int> > antiNodes;

bool outOfBounds(const int x, const int y, const int size) {
    return x < 0 || x >= size || y < 0 || y >= size;
}

void calculateAntiNodes(const vector< pair<int, int> >& antennaLocations, const int matSize) {
    const auto n = antennaLocations.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            const auto ix = antennaLocations[i].first;
            const auto iy = antennaLocations[i].second;
            const auto jx = antennaLocations[j].first;
            const auto jy = antennaLocations[j].second;
            const auto dx = jx - ix;
            const auto dy = jy - iy;

            if (!outOfBounds(ix - dx, iy - dy, matSize)) {
                antiNodes.insert({ix - dx, iy - dy});
            }

            if (!outOfBounds(jx + dx, jy + dy, matSize)) {
                antiNodes.insert({jx + dx, jy + dy});
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

        const auto n = mat.size();
        vector< pair<int, int> > antennas[256];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isalnum(mat[i][j])) {
                    antennas[mat[i][j]].push_back({i, j});
                }
            }
        }

        for (int i = 0; i < 256; i++) {
            if (antennas[i].empty()) {
                continue;
            }

            calculateAntiNodes(antennas[i], n);
        }
    }

    cout << antiNodes.size() << endl;


    return 0;
}