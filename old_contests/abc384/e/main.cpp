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
    int h, w;
    ll x;
    cin >> h >> w >> x;
    int p, q;
    cin >> p >> q;
    --p;
    --q;
    vector<vector<ll>> s(h, vector<ll>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> s[i][j];
        }
    }

    ll pow = s[p][q];
    // tupleはs[i][j], i, j
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> queue;
    vector<vector<bool>> checked(h, vector<bool>(w, false));
    checked[p][q] = true;

    auto pushIfNotCheckThenCheck = [&](int i, int j) {
        if (!checked[i][j]) {
            queue.emplace(s[i][j], i, j);
            checked[i][j] = true;
        }
    };

    auto pushNextCells = [&](int i, int j) {
        if (i > 0) pushIfNotCheckThenCheck(i - 1, j);
        if (i < h - 1) pushIfNotCheckThenCheck(i + 1, j);
        if (j > 0) pushIfNotCheckThenCheck(i, j - 1);
        if (j < w - 1) pushIfNotCheckThenCheck(i, j + 1);
    };

    pushNextCells(p, q);

    while (queue.size() > 0) {
        auto [sp, i, j] = queue.top();
        queue.pop();
        if (pow % x == 0LL ? sp < pow / x : sp <= pow / x) {
            pow += sp;
            pushNextCells(i, j);
        }
    }
    
    cout << pow << endl;

    return 0;
}