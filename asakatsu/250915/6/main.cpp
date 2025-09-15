#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, nq;
    cin >> n >> nq;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<ll, ll>> seg(nq);
    vector<ll> segIndex(nq);
    for (ll qi = 0; qi < nq; ++qi) {
        cin >> seg[qi].first >> seg[qi].second;
        --seg[qi].first;
        segIndex[qi] = qi;
    }

    ll m = sqrt(n);
    auto comp = [&](pair<ll, ll> x, pair<ll, ll> y) {
        if (x.first / m < y.first / m) return true;
        if (x.first / m == y.first / m) return x.second < y.second;
        return false;
    };
    sort(segIndex.begin(), segIndex.end(), [&](ll i, ll j) { return comp(seg[i], seg[j]); });
    sort(seg.begin(), seg.end(), comp);

    vector<ll> answers(nq);
    ll ans = 0;
    unordered_map<ll, ll> countMap;
    for (ll i = seg[0].first; i < seg[0].second; ++i) {
        ++countMap[a[i]];
    }
    for (const auto &[v, c] : countMap) {
        ans += c * (c-1) * (c-2) / 6;
    }
    answers[segIndex[0]] = ans;

    for (ll qi = 1; qi < nq; ++qi) {
        if (seg[qi-1].second < seg[qi].second) {
            for (ll i = seg[qi-1].second; i < seg[qi].second; ++i) {
                ll c = countMap[a[i]];
                ans += c * (c-1) / 2;
                ++countMap[a[i]];
            }
        } else if (seg[qi-1].second > seg[qi].second) {
            for (ll i = seg[qi-1].second - 1; i >= seg[qi].second; --i) {
                ll c = countMap[a[i]];
                ans -= (c-1) * (c-2) / 2;
                --countMap[a[i]];
            }
        }
        
        if (seg[qi-1].first < seg[qi].first) {
            for (ll i = seg[qi-1].first; i < seg[qi].first; ++i) {
                ll c = countMap[a[i]];
                ans -= (c-1) * (c-2) / 2;
                --countMap[a[i]];
            }
        } else if (seg[qi-1].first > seg[qi].first) {
            for (ll i = seg[qi-1].first - 1; i >= seg[qi].first; --i) {
                ll c = countMap[a[i]];
                ans += c * (c-1) / 2;
                ++countMap[a[i]];
            }
        }

        answers[segIndex[qi]] = ans;
    }

    for (ll qi = 0; qi < nq; ++qi) {
        cout << answers[qi] << endl;
    }

    return 0;
}