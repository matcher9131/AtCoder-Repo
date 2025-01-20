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
    ll n;
    int m;
    cin >> n >> m;
    vector<pair<ll, ll>> queens(m);
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        queens[i] = make_pair(a, b);
    }

    // i = kとなるラインが占められているかどうか
    set<ll> row;
    // j = kとなるラインが占められているかどうか
    set<ll> column;
    // i + j = kとなるラインが占められているかどうか
    set<ll> diaur;
    // i - j = kとなるラインが占められているかどうか
    set<ll> dialr;
    for (const auto& [i, j]: queens) {
        row.insert(i);
        column.insert(j);
        diaur.insert(i + j);
        dialr.insert(i - j);
    }

    ll nA = n * row.size();
    ll nB = n * column.size();
    ll nAB = row.size() * column.size();
    ll nC = 0, nD = 0, nAC = 0, nAD = 0, nBC = 0, nBD = 0, nCD = 0, nABC = 0, nABD = 0, nACD = 0, nBCD = 0, nABCD = 0;
    
    for (const ll k : diaur) {
        if (k < n) nC += k + 1;
        else nC += 2 * n - k - 1;
    }
    for (const ll k : dialr) {
        if (k >= 0) nD += n - k;
        else nD += n + k;
    }

    for (const ll i : row) {
        for (const ll k : diaur) {
            ll j = k - i;
            if (0 <= j && j < n) {
                ++nAC;
                if (column.contains(j)) {
                    ++nABC;
                    if (dialr.contains(i - j)) {
                        ++nABCD;
                    }
                }
            }
        }
        for (const ll k : dialr) {
            ll j = i - k;
            if (0 <= j && j < n) {
                ++nAD;
                if (column.contains(j)) {
                    ++nABD;
                }
            }
        }
    }
    for (const ll j : column) {
        for (const ll k : diaur) {
            ll i = k - j;
            if (0 <= i && i < n) ++nBC;
        }
        for (const ll k : dialr) {
            ll i = k + j;
            if (0 <= i && i < n) ++nBD;
        }
    }
    for (const ll k1 : diaur) {
        for (const ll k2 : dialr) {
            if ((k1 + k2) % 2 != 0) continue;
            ll i = (k1 + k2) / 2;
            ll j = (k1 - k2) / 2;
            if (0 <= i && i < n && 0 <= j && j < n) {
                ++nCD;
                if (row.contains(i)) ++nACD;
                if (column.contains(j)) ++nBCD;
            }
        }
    }

    ll numNgCells = nA + nB + nC + nD
                    - nAB - nAC - nAD - nBC - nBD - nCD
                    + nABC + nABD + nACD + nBCD
                    - nABCD;

    cout << n * n - numNgCells << endl;

    return 0;
}