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
    int m;
    cin >> m;
    vector<ll> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int l;
    cin >> l;
    vector<ll> c(l);
    for (int i = 0; i < l; ++i) {
        cin >> c[i];
    }

    set<ll> s;
    for (const ll ai : a) {
        for (const ll bi : b) {
            for (const ll ci : c) {
                s.insert(ai + bi + ci);
            }
        }
    }

    int nq;
    cin >> nq;
    while (nq--) {
        ll qi;
        cin >> qi;
        cout << (s.contains(qi) ? "Yes" : "No") << endl;
    }

    return 0;
}