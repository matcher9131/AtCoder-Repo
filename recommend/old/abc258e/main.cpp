#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, nq, x;
    cin >> n >> nq >> x;
    vector<ll> w(2*n);
    for (ll i = 0; i < n; ++i) {
        cin >> w[i];
        w[n+i] = w[i];
    }
    vector<ll> s(2*n+1);
    for (ll i = 0; i < 2*n; ++i) {
        s[i+1] = s[i] + w[i];
    }
    ll xExtra = x / s[n];
    x %= s[n];

    vector<int> dist(n, -1);
    ll v = 0;
    vector<ll> st;
    while (dist[v] == -1) {
        ll nv = lower_bound(s.begin(), s.end(), s[v] + x) - s.begin();
        ll count = nv - v;
        dist[v] = st.size();
        st.push_back(count);
        v = nv % n;
    }
    ll headLength = dist[v];
    ll cycleLength = (ll)st.size() - headLength;
    
    while (nq--) {
        ll k;
        cin >> k;
        --k;
        if (k < headLength) {
            cout << st[k] + n * xExtra << endl;
        } else {
            k -= headLength;
            cout << st[headLength + k % cycleLength] + n * xExtra << endl;
        }
    }

    return 0;
}