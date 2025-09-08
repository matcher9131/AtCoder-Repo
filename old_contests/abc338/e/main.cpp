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
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    // R, L
    vector<pair<int, int>> x(n);
    atcoder::fenwick_tree<int> fw(2 * n);
    for (int i = 0; i < n; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;
        if (ai > bi) swap(ai, bi);
        x[i] = { bi, ai };
        fw.add(ai, 1);
    }
    sort(x.begin(), x.end());

    for (const auto &[r, l] : x) {
        if (fw.sum(l + 1, r)) {
            cout << "Yes" << endl;
            return 0;
        }
        fw.add(l, -1);
    }

    cout << "No" << endl;
    return 0;
}