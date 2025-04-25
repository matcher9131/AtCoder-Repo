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

    // [from, to)
    vector<pair<ll, ll>> suc;
    for (const ll ai : a) {
        if (suc.empty()) {
            suc.emplace_back(ai, ai + 1);
        } else {
            auto [from, to] = suc.back();
            if (from == ai) {
                suc.pop_back();
                if (!suc.empty() && suc.back().first == to + 1) {
                    suc.back().first = to;
                } else {
                    suc.emplace_back(to, to + 1);
                }
            } else if (from == ai + 1) {
                suc.back().first = ai;
            } else {
                suc.emplace_back(ai, ai + 1);
            }
        }
    }

    cout << accumulate(suc.begin(), suc.end(), 0LL, [](ll acc, pair<ll, ll>& element) {
        return acc + element.second - element.first;
    }) << endl;

    return 0;
}