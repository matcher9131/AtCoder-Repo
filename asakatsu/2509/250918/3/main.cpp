#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, x;
    string s;
    cin >> n >> x >> s;

    stack<char> st;
    ll numU = 0;
    for (ll i = n - 1; i >= 0; --i) {
        if (s[i] == 'U') {
            ++numU;
        } else {
            if (numU > 0) --numU;
            else st.push(s[i]);
        }
    }
    for (ll i = 0; i < numU; ++i) {
        st.push('U');
    }

    while (!st.empty()) {
        char c = st.top();
        st.pop();
        if (c == 'U') x >>= 1;
        else if (c == 'L') x <<= 1;
        else x = 2*x + 1;
    }

    cout << x << endl;
    return 0;
}