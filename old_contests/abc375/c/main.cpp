#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    auto rotate = [&](pair<int, int> p) -> pair<int, int> {
        return make_pair(p.second, n - 1 - p.first);
    };
    auto rotateN = [&](pair<int, int> p, int num) -> pair<int, int> {
        int n = num % 4;
        return n == 0 ? rotate(p)
            : n == 1 ? rotate(rotate(p))
            : n == 2 ? rotate(rotate(rotate(p)))
            : p;
    };

    vector<string> t(n, string(n, '.'));
    for (int i = 0; i < n / 2; ++i) {
        // (i, y)  (i <= y <= N - 1 - i)
        for (int y = i; y <= n - 1 - i; ++y) {
            auto [dstX, dstY] = rotateN(make_pair(i, y), i);
            t[dstX][dstY] = s[i][y];
        }
        // (N - 1 - i, y)　(i <= y <= N - 1 - i)
        for (int y = i; y <= n - 1 - i; ++y) {
            auto [dstX, dstY] = rotateN(make_pair(n - 1 - i, y), i);
            t[dstX][dstY] = s[n - 1 - i][y];
        }
        // (x, i)  (i + 1 <= x <= N - 2 - i)
        for (int x = i + 1; x <= n - 2 - i; ++x) {
            auto [dstX, dstY] = rotateN(make_pair(x, i), i);
            t[dstX][dstY] = s[x][i];
        }
        // (x, N - 1 - i)  (i + 1 <= x <= N - 2 - i)
        for (int x = i + 1; x <= n - 2 - i; ++x) {
            auto [dstX, dstY] = rotateN(make_pair(x, n - 1 - i), i);
            t[dstX][dstY] = s[x][n - 1 - i];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << t[i] << endl;
    }
    
    return 0;
}