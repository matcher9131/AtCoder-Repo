#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll ti, tj, ai, aj;
    cin >> ti >> tj >> ai >> aj;
    ll n, m, l;
    cin >> n >> m >> l;
    vector<pair<char, ll>> s(m);
    for (ll i = 0; i < m; ++i) {
        char si;
        ll ai;
        cin >> si >> ai;
        s[i] = { si, ai };
    }
    vector<pair<char, ll>> t(l);
    for (ll i = 0; i < l; ++i) {
        char ti;
        ll bi;
        cin >> ti >> bi;
        t[i] = { ti, bi };
    }

    vector<ll> ss(m);
    ss[0] = s[0].second;
    for (ll i = 1; i < m; ++i) {
        ss[i] = ss[i-1] + s[i].second;
    }
    vector<ll> st(l);
    st[0] = t[0].second;
    for (ll i = 1; i < l; ++i) {
        st[i] = st[i-1] + t[i].second;
    }

    map<char, pair<ll, ll>> dir;
    dir['U'] = { -1, 0 };
    dir['D'] = { 1, 0 };
    dir['L'] = { 0, -1 };
    dir['R'] = { 0, 1 };

    ll ans = 0;
    ll i = 0, j = 0, k = 0;
    while (i < n) {
        ll ni = ss[j] > st[k] ? st[k] : ss[j];
        ll dif = ni - i;
        auto [dit, djt] = dir[s[j].first];
        auto [dia, dja] = dir[t[k].first];

        if (s[j].first == t[k].first) {
            if (ti == ai && tj == aj) ans += dif;
        } else {
            // c(dit-dia) = ai-ti
            // c(djt-dja) = aj-tj
            if (dit == dia) {
                if (ai-ti == 0 && (aj-tj) % (djt-dja) == 0) {
                    ll c = (aj-tj) / (djt-dja);
                    if (0 < c && c <= dif) ++ans;
                }
            } else if (djt == dja) {
                if (aj-tj == 0 && (ai-ti) % (dit-dia) == 0) {
                    ll c = (ai-ti) / (dit-dia);
                    if (0 < c && c <= dif) ++ans;
                }
            } else {
                if ((ai-ti) % (dit-dia) == 0 && (aj-tj) % (djt-dja) == 0) {
                    ll c1 = (ai-ti) / (dit-dia);
                    ll c2 = (aj-tj) / (djt-dja);
                    if (c1 == c2 && 0 < c1 && c1 <= dif) ++ans;
                }
            }
        }

        ti += dif * dit;
        tj += dif * djt;
        ai += dif * dia;
        aj += dif * dja;

        i = ni;
        if (ss[j] > st[k]) ++k;
        else if (ss[j] < st[k]) ++j;
        else {
            ++j;
            ++k;
        }
    }

    cout << ans << endl;
    return 0;
}