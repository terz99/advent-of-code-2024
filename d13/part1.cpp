
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = (1 << 30) - 1;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1);
    }
};

struct Node {
    int tokens, x, y;
    Node(){}
    Node(const int tokens, const int x, const int y) {
        this->tokens = tokens;
        this->x = x;
        this->y = y;
    }

    bool operator<(const Node& other) const {
        return this->tokens < other.tokens;
    } 

    bool operator>(const Node& other) const {
        return this->tokens < other.tokens;
    } 
};

pair<int, int> getButtonValues(const string& s) {
    return {stoi(s.substr(12, 2)), stoi(s.substr(18, 2))};
}

pair<int, int> getPrizeLocation(const string& s) {
    int i = 9;
    string x, y;
    x = y = "";
    while (isdigit(s[i])) {
        x += s[i++];
    }
    while (!isdigit(s[i])) {
        i++;
    }
    while (i < s.length()) {
        y += s[i++];
    }

    return {stoi(x), stoi(y)};
}

int getValue(const pair<int, int> key, unordered_map<pair<int, int>, int, pair_hash>& m) {
    if (m.find(key) == m.end()) {
        m[key] = INF;
    }
    return m[key];
}

int solve(
    const pair<int, int> aButton, 
    const pair<int, int> bButton, 
    const pair<int, int> prizeLocation 
) {
    unordered_map<pair<int, int>, int, pair_hash> dist;
    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push(Node(0, 0, 0));
    dist[{0, 0}] = 0;

    while (!q.empty()) {
        const auto curr = q.top();
        q.pop();

        auto nx = curr.x + aButton.first;
        auto ny = curr.y + aButton.second;


        if (nx <= prizeLocation.first && ny <= prizeLocation.second) {
            if (getValue({nx, ny}, dist) > getValue({curr.x, curr.y}, dist) + 3) {
                dist[{nx, ny}] = dist[{curr.x, curr.y}] + 3;
                q.push(Node(dist[{nx, ny}], nx, ny));
            }
        }

        nx = curr.x + bButton.first;
        ny = curr.y + bButton.second;


        if (nx <= prizeLocation.first && ny <= prizeLocation.second) {
            if (getValue({nx, ny}, dist) > getValue({curr.x, curr.y}, dist) + 1) {
                dist[{nx, ny}] = dist[{curr.x, curr.y}] + 1;
                q.push(Node(dist[{nx, ny}], nx, ny));
            }
        }
    }

    return getValue({prizeLocation.first, prizeLocation.second}, dist);
}

int main() {
    ifstream in;
    // in.open("test_input.in");
    in.open("input.in");
    int res = 0;
    if (in.is_open()) {
       string a, b, p, tmp;

       while (getline(in, a)) {
            getline(in, b);
            getline(in, p);
            getline(in, tmp);

            
            const auto aButton = getButtonValues(a);
            const auto bButton = getButtonValues(b);
            const auto prizeLocation = getPrizeLocation(p);

            const auto currResult = solve(aButton, bButton, prizeLocation);
            if (currResult != INF) {
                res += currResult;
            }
       }

       cout << res << endl;
       
    }



    return 0;
}