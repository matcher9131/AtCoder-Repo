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

constexpr ll INF = 1LL << 60;

int main() {
    int n;
    ll a, b, c;
    cin >> n >> a >> b >> c;
    ll ab = a / gcd(a, b) * b, bc = b / gcd(b, c) * c, ca = c / gcd(c, a) * a;
    ll abc = ab / gcd(ab , c) * c;
    vector<vector<ll>> r(7, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        r[0][i] = x % a == 0 ? 0 : a - x % a;
        r[1][i] = x % b == 0 ? 0 : b - x % b;
        r[2][i] = x % c == 0 ? 0 : c - x % c;
        r[3][i] = x % ab == 0 ? 0 : ab - x % ab;
        r[4][i] = x % bc == 0 ? 0 : bc - x % bc;
        r[5][i] = x % ca == 0 ? 0 : ca - x % ca;
        r[6][i] = x % abc == 0 ? 0 : abc - x % abc;
    }

    ll ans = 1LL << 60;
    vector<vector<ll>> t = r;
    vector<int> perm{ 0, 1, 2 };
    do {
        auto it0 = min_element(t[perm[0]].begin(), t[perm[0]].end());
        t[perm[1]][it0 - t[perm[0]].begin()] = INF;
        t[perm[2]][it0 - t[perm[0]].begin()] = INF;
        auto it1 = min_element(t[perm[1]].begin(), t[perm[1]].end());
        t[perm[2]][it1 - t[perm[1]].begin()] = INF;
        auto it2 = min_element(t[perm[2]].begin(), t[perm[2]].end());
        ans = min(ans, *it0 + *it1 + *it2);
        t[perm[1]][it0 - t[perm[0]].begin()] = r[perm[1]][it0 - t[perm[0]].begin()];
        t[perm[2]][it0 - t[perm[0]].begin()] = r[perm[2]][it0 - t[perm[0]].begin()];
        t[perm[2]][it1 - t[perm[1]].begin()] = r[perm[2]][it1 - t[perm[1]].begin()];
    } while (next_permutation(perm.begin(), perm.end()));

    {
        auto it3 = min_element(t[3].begin(), t[3].end());
        t[2][it3 - t[3].begin()] = INF;
        auto it2 = min_element(t[2].begin(), t[2].end());
        ans = min(ans, *it3 + *it2);
        t[2][it3 - t[3].begin()] = r[2][it3 - t[3].begin()];
    }
    {
        auto it2 = min_element(t[2].begin(), t[2].end());
        t[3][it2 - t[2].begin()] = INF;
        auto it3 = min_element(t[3].begin(), t[3].end());
        ans = min(ans, *it3 + *it2);
        t[3][it2 - t[2].begin()] = r[3][it2 - t[2].begin()];
    }
    
    {
        auto it4 = min_element(t[4].begin(), t[4].end());
        t[0][it4 - t[4].begin()] = INF;
        auto it0 = min_element(t[0].begin(), t[0].end());
        ans = min(ans, *it4 + *it0);
        t[0][it4 - t[4].begin()] = r[0][it4 - t[4].begin()];
    }
    {
        auto it0 = min_element(t[0].begin(), t[0].end());
        t[4][it0 - t[0].begin()] = INF;
        auto it4 = min_element(t[4].begin(), t[4].end());
        ans = min(ans, *it4 + *it0);
        t[4][it0 - t[0].begin()] = r[4][it0 - t[0].begin()];
    }
    
    {
        auto it5 = min_element(t[5].begin(), t[5].end());
        t[1][it5 - t[5].begin()] = INF;
        auto it1 = min_element(t[1].begin(), t[1].end());
        ans = min(ans, *it5 + *it1);
        t[1][it5 - t[5].begin()] = r[1][it5 - t[5].begin()];
    }
    {
        auto it1 = min_element(t[1].begin(), t[1].end());
        t[5][it1 - t[1].begin()] = INF;
        auto it5 = min_element(t[5].begin(), t[5].end());
        ans = min(ans, *it5 + *it1);
        t[5][it1 - t[1].begin()] = r[5][it1 - t[1].begin()];
    }
    
    {
        auto it6 = min_element(r[6].begin(), r[6].end());
        ans = min(ans, *it6);
    }

    cout << ans << endl;

    return 0;
}