#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using ll = long long;
using namespace std;
using namespace std::chrono;

constexpr int INF = 1e8;

void run() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int m;
    cin >> m;
    vector<vector<int>> dis(n, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        dis[x][y] = 1;
        dis[y][x] = 1;
    }

    vector<int> perm;
    for (int i = 0; i < n; ++i) {
        perm.push_back(i);
    }

    auto calcTime = [&]() {
        int t = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (dis[perm[i]][perm[i + 1]]) {
                return INF;
            }
            t += a[perm[i]][i];
        }
        t += a[perm[n - 1]][n - 1];
        return t;
    };

    int min = INF;
    do {
        int t = calcTime();
        if (t < min) min = t;
    } while(next_permutation(perm.begin(), perm.end()));

    cout << (min != INF ? min : -1) << endl;
}

int main() {
    auto start = system_clock::now();
    run();
    auto end = system_clock::now();
    auto elapsedMsec = duration_cast<milliseconds>(end - start).count();
    cout << elapsedMsec << "msec" << endl;
    
    return 0;
}