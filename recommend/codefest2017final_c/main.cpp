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

int minSeqDif(vector<int> &v) {
    int ans = 25;
    for (int i = 1; i < v.size(); ++i) {
        ans = min(ans, v[i] - v[i - 1]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> d(13);
    d[0] = 1;
    for (int i = 0; i < n; ++i) {
        int di;
        cin >> di;
        ++d[di];
    }

    if (n >= 24) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < 13; ++i) {
        if (d[i] >= 3) {
            cout << 0 << endl;
            return 0;
        }
    }
    if (d[0] >= 2 || d[12] >= 2) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << 12); bit += 2) {
        vector<int> t;
        t.reserve(n + 1);
        t.emplace_back(0);
        if (d[12] == 1) t.emplace_back(12);
        for (int i = 1; i < 12; ++i) {
            if (d[i] == 1) {
                t.emplace_back((bit & (1 << i)) ? i : -i);
            } else if (d[i] == 2) {
                t.emplace_back(i);
                t.emplace_back(-i);
            }
        }
        sort(t.begin(), t.end());
        t.push_back(t[0] + 24);
        ans = max(ans, minSeqDif(t));
    }

    cout << ans << endl;

    return 0;
}