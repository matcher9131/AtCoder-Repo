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
#include <atcoder/dsu>
using namespace std;
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    // cost, vertexes
    vector<pair<ll, vector<int>>> groups(m);
    for (int i = 0; i < m; ++i) {
        ll k, c;
        cin >> k >> c;
        groups[i] = { c, vector<int>() };
        for (int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            --a;
            groups[i].second.push_back(a);
        }
    }
    sort(groups.begin(), groups.end());

    atcoder::dsu d(n + m);
    ll ans = 0;
    for (int mi = 0; mi < m; ++mi) {
        ll edges = 0;
        for (const int to : groups[mi].second) {
            if (!d.same(n + mi, to)) {
                d.merge(n + mi, to);
                ++edges;
            }
        }
        ans += (edges - 1) * groups[mi].first;
    }
    
    cout << (d.size(0) == n + m ? ans : -1) << endl;

    return 0;
}