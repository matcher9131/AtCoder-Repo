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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;


int main() {
    int h, w, d;
    cin >> h >> w >> d;
    int n = h * w;
    // 整数iが書かれたマスの座標(x, y)　※i,x,yともに0-indexed
    vector<pair<int, int>> address(n);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int a;
            cin >> a;
            --a;
            address[a] = make_pair(i, j);
        }
    }
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    for (int i = 0; i < q; ++i) {
        int li, ri;
        cin >> li >> ri;
        --li;
        --ri;
        l[i] = li;
        r[i] = ri;
    }

    // i → i + D → i + 2D → … と移動したときのコストの累積和(0-indexed)
    vector<ll> cost(n);
    for (int i = d; i < n; ++i) {
        auto from = address[i - d];
        auto to = address[i];
        cost[i] = cost[i - d] + abs(from.first - to.first) + abs(from.second - to.second);
    }

    for (int i = 0; i < q; ++i) {
        cout << cost[r[i]] - cost[l[i]] << endl;
    }

    return 0;
}
