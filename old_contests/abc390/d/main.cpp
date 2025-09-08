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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_set<ll> s;
    vector<ll> b;
    function<void(int)> dfs = [&](int i) -> void {
        if (i == n) {
            ll x = 0;
            for (const ll bi : b) {
                x ^= bi;
            }
            s.insert(x);
            return;
        }
        // bのいずれかの要素に加算
        for (int j = 0; j < b.size(); ++j) {
            b[j] += a[i];
            dfs(i + 1);
            b[j] -= a[i];
        }
        // bに新たに挿入
        b.push_back(a[i]);
        dfs(i + 1);
        b.pop_back();
    };
    dfs(0);

    cout << s.size() << endl;

    return 0;
}