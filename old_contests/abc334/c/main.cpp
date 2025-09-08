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
    int n, k;
    cin >> n >> k;
    unordered_set<int> a;
    for (int i = 0; i < k; ++i) {
        int ai;
        cin >> ai;
        --ai;
        a.insert(ai);
    }

    vector<int> b;
    b.reserve(2*n);
    for (int i = 0; i < n; ++i) {
        if (a.contains(i)) {
            b.push_back(i);
        } else {
            b.push_back(i);
            b.push_back(i);
        }
    }

    if (k%2) {
        vector<ll> s0((2*n - k) / 2 + 1), s1((2*n - k) / 2 + 1);
        for (int i = 0; i < (2*n - k) / 2; ++i) {
            s0[i+1] = b[2*i+1] - b[2*i];
            s0[i+1] += s0[i];
            s1[i+1] = b[2*i+2] - b[2*i+1];
            s1[i+1] += s1[i];
        }
        ll ans = 1e16;
        for (int i = 0; i < (2*n - k) / 2; ++i) {
            ans = min(ans, s0[i] - s0[0] + s1.back() - s1[i]);
        }

        cout << ans << endl;
    } else {
        ll ans = 0;
        for (int i = 0; i < (2 * n - k) / 2; ++i) {
            ans += b[2*i+1] - b[2*i];
        }

        cout << ans << endl;
    }
    
    return 0;
}