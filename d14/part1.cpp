
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = (1 << 30) - 1;
const int WIDE = 101;
const int TALL = 103;
const int WIDE_HALF = WIDE / 2;
const int TALL_HALF = TALL / 2;
const int MULTIPLIER = 100;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

struct Robot {
    int x, y, vx, vy;
    Robot(){}
    Robot(const int x, const int y, const int vx, const int vy) {
        this->x = x;
        this->y = y;
        this->vx = vx;
        this->vy = vy;
    }
};

Robot extractInput(const string& s) {
    string x, y, vx, vy;
    int i = 2;
    while (isdigit(s[i])) {
        y += s[i++];
    }

    i++;
    while(isdigit(s[i])) {
        x += s[i++];
    }

    while (s[i] != '=') {
        i++;
    }
    i++;

    while (isdigit(s[i]) || s[i] == '-') {
        vy += s[i++];
    }

    i++;
    while (isdigit(s[i]) || s[i] == '-') {
        vx += s[i++];
    }

    return Robot(stoi(x), stoi(y), stoi(vx), stoi(vy));
}

int main() {
    ifstream in;
    // in.open("test_input.in");
    in.open("input.in");
    if (in.is_open()) {
        string line;
        vector<Robot> robots;
        while(getline(in, line)) {
            robots.push_back(extractInput(line));
        }

        vector< vector<int> > mat(TALL, vector<int>(WIDE, 0));
        for (const auto robot : robots) {
            auto finalX = (robot.x + MULTIPLIER*(robot.vx)) % TALL;
            auto finalY = (robot.y + MULTIPLIER*(robot.vy)) % WIDE;

            if (finalX < 0) {
                finalX = TALL + finalX;
            }
            if (finalY < 0) {
                finalY = WIDE + finalY;
            }
            mat[finalX][finalY]++;
        }

        int q1, q2, q3, q4;
        q1 = q2 = q3 = q4 = 0;
        for (int i = 0; i < TALL; i++) {
            for (int j = 0; j < WIDE; j++) {
                if (i == TALL_HALF || j == WIDE_HALF) {
                    continue;
                }

                if (i < TALL_HALF) {
                    if (j < WIDE_HALF) {
                        q1 += mat[i][j];
                    } else {
                        q2 += mat[i][j];
                    }
                } else {
                    if (j < WIDE_HALF) {
                        q3 += mat[i][j];
                    } else {
                        q4 += mat[i][j];
                    }
                }
            }
        }
        
        cout << q1*q2*q3*q4 << endl;
    }



    return 0;
}