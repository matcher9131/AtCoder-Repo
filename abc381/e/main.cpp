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
    int n, m;
    string s;
    cin >> n >> m >> s;
    // l, r
    vector<pair<int, int>> q(m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        q[i] = make_pair(l, r);
    }

    vector<int> i1, i2, is;
    for (int i = 0; i < n; ++i) {
        switch (s[i]) {
            case '1':
                i1.push_back(i);
                break;
            case '2':
                i2.push_back(i);
                break;
            case '/':
                is.push_back(i);
                break;
            default:
                break;
        }
    }

    // [l,r]に2m+1文字の11/22文字列が存在するか
    auto exists = [&](int m, int l, int r) {
        if (m == 0) {
            return lower_bound(is.begin(), is.end(), l) != upper_bound(is.begin(), is.end(), r);
        }
        int i1i = lower_bound(i1.begin(), i1.end(), l) - i1.begin();
        if (i1i + m - 1 >= i1.size()) return false;
        int ls = i1[i1i + m - 1] + 1;
        int isi = lower_bound(is.begin(), is.end(), ls) - is.begin();
        if (isi >= is.size()) return false;
        if (is[isi] > r) return false;
        int l2 = is[isi] + 1;
        int i2i = lower_bound(i2.begin(), i2.end(), l2) - i2.begin();
        if (i2i + m - 1 >= i2.size()) return false;
        int r2 = i2[i2i + m - 1];
        return r2 <= r;
    };

    for (const auto& [l, r] : q) {
        int ng = n + 1;
        int ok = -1;

        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (exists(mid, l, r)) ok = mid;
            else ng = mid;
        }
        cout << (ok == -1 ? 0 : 2 * ok + 1) << endl;
    }

    return 0;
}