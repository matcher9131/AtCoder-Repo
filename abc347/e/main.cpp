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
    int n, nq;
    cin >> n >> nq;
    vector<int> q(nq);
    for (int i = 0; i < nq; ++i) {
        cin >> q[i];
        --q[i];
    }

    vector<ll> ans(n);
    vector<int> l(n, -1);
    atcoder::fenwick_tree<ll> fw(nq);
    int ss = 0;
    for (int qi = 0; qi < nq; ++qi) {
        int x = q[qi];
        if (l[x] == -1) {
            l[x] = qi;
            ++ss;
            fw.add(qi, ss);
        } else {
            ans[x] += fw.sum(l[x], qi);
            l[x] = -1;
            --ss;
            fw.add(qi, ss);
        }
    }
    for (int x = 0; x < n; ++x) {
        if (l[x] != -1) {
            ans[x] += fw.sum(l[x], nq);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}