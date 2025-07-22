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
constexpr ll INF = 1e16;

int main() {
    ll nq, a0, b0;
    cin >> nq >> a0 >> b0;
    set<ll> s;
    s.insert(-INF);
    s.insert(INF);
    s.insert(a0 + b0);
    s.insert(a0 - b0);

    while (nq--) {
        ll type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            s.insert(a + b);
            s.insert(a - b);
        } else {
            auto itl = s.lower_bound(a);
            auto itr = s.lower_bound(b);
            if (itl != itr) {
                cout << 0 << endl;
            } else {
                --itl;
                cout << min(a - *itl, *itr - b) << endl;
            }
        }
    }

    return 0;
}