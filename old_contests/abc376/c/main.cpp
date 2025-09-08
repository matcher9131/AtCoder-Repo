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

constexpr int INF = 1e9 + 1;

int main() {
    int n;
    cin >> n;
    multiset<int> a, b;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a.insert(ai);
    }
    for (int i = 0; i < n - 1; ++i) {
        int bi;
        cin >> bi;
        b.insert(bi);
    }

    int ng = 0;
    int ok = INF;
    auto isOK = [&](int x) {
        for (auto ia = a.begin(), ib = b.begin(); ia != a.end() && ib != b.end(); ++ia, ++ib) {
            if (*ia > *ib) return false;
        }
        return true;
    };

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        b.insert(mid);
        if (isOK(mid)) ok = mid;
        else ng = mid;
        b.erase(b.find(mid));
    }

    cout << (ok == INF ? -1 : ok) << endl;

    return 0;
}