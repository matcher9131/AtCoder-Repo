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
using namespace std;
using ll = long long;

constexpr ll INF = 1e12;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a{ INF };
    priority_queue<ll> b, c;
    a.reserve(n + 1);
    for (int i = 0; i < n; ++i) {
        int t;
        ll x;
        cin >> t >> x;
        if (t == 0) a.push_back(x);
        else if (t == 1) b.push(x);
        else if (t == 2) c.push(x);
    }
    sort(a.begin(), a.end(), greater<ll>());
    a[0] = 0;
    for (int i = 1; i < a.size(); ++i) {
        a[i] += a[i - 1];
    }
    ll aBack = a.back();
    for (int i = 0; i <= m; ++i) {
        a.push_back(aBack);
    }
    
    vector<ll> d{ 0 };
    d.reserve(n + 1);
    ll rest = 0;
    while (d.size() <= m && !b.empty() || !c.empty()) {
        if (rest == 0) {
            if (c.empty()) {
                b.pop();
                d.push_back(d.back());
            } else {
                rest = c.top();
                c.pop();
                d.push_back(d.back());
            }
        } else {
            if (b.empty()) {
                c.pop();
                d.push_back(d.back());
            } else {
                ll newValue = d.back() + b.top();
                b.pop();
                d.push_back(newValue);
                --rest;
            }
        }
    }
    ll dBack = d.back();
    for (int i = 0; i < m; ++i) {
        d.push_back(dBack);
    }

    ll maxValue = 0;

    for (int i = 0; i <= m; ++i) {
        ll value = a[i] + d[m - i];
        if (value > maxValue) maxValue = value;
    }
    
    cout << maxValue << endl;

    return 0;
}