#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> sumCount(4);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ++sumCount[a[i]];
    }
    for (ll i = 0; i < 3; ++i) {
        sumCount[i+1] += sumCount[i];
    }

    // ソート後にxになるべき場所にいる値yのインデックスの集合
    vector<vector<set<ll>>> s(4, vector<set<ll>>(4));
    {
        ll i = 0;
        for (ll k = 0; k < 4; ++k) {
            for (; i < sumCount[k]; ++i) {
                if (a[i] != k) s[k][a[i]].insert(i);
            }
        }
    }

    ll ans = 0;
    for (ll x = 0; x < 3; ++x) {
        for (ll y = x+1; y < 4; ++y) {
            while (!s[x][y].empty() && !s[y][x].empty()) {
                s[x][y].erase(s[x][y].begin());
                s[y][x].erase(s[y][x].begin());
                ++ans;
            }
        }
    }

    vector<ll> perm(4);
    for (ll i = 0; i < 4; ++i) {
        perm[i] = i;
    }
    do {
        ll x = perm[0], y = perm[1], z = perm[2];
        while (!s[x][y].empty() && !s[y][z].empty() && !s[z][x].empty()) {
            s[x][y].erase(s[x][y].begin());
            s[y][z].erase(s[y][z].begin());
            s[z][x].erase(s[z][x].begin());
            ans += 2;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    sort(perm.begin(), perm.end());
    do {
        ll x = perm[0], y = perm[1], z = perm[2], w = perm[3];
        while (!s[x][y].empty() && !s[y][z].empty() && !s[z][w].empty() && !s[w][x].empty()) {
            s[x][y].erase(s[x][y].begin());
            s[y][z].erase(s[y][z].begin());
            s[z][w].erase(s[z][w].begin());
            s[w][x].erase(s[w][x].begin());
            ans += 3;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << ans << endl;
    return 0;
}