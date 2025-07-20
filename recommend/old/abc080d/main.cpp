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
    ll n, c;
    cin >> n >> c;
    vector<set<pair<ll, ll>>> ch(c);
    for (ll i = 0; i < n; ++i) {
        ll si, ti, ci;
        cin >> si >> ti >> ci;
        --ci;
        ch[ci].emplace(si, ti);
    }

    for (ll ci = 0; ci < c; ++ci) {
        if ((int)ch[ci].size() < 2) continue;
        auto left = ch[ci].end(), right = ch[ci].end();
        --left;
        --left;
        --right;
        while (true) {
            if (right->first - left->second <= 1) {
                ll s = left->first, t = right->second;
                ch[ci].erase(right);
                ch[ci].erase(left);
                left = ch[ci].emplace(s, t).first;
                right = ch[ci].end();
            }
            if (left == ch[ci].begin()) break;
            --left;
            --right;
        }
    }

    vector<ll> sum(1e5+1);
    for (ll ci = 0; ci < c; ++ci) {
        for (const auto &[si, ti] : ch[ci]) {
            ++sum[si-1];
            --sum[ti];
        }
    }

    for (ll i = 1; i < (ll)sum.size(); ++i) {
        sum[i] += sum[i-1];
    }

    cout << *max_element(sum.begin(), sum.end()) << endl;
    return 0;
}