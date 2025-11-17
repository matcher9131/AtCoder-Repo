#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    long double a, b;
    cin >> a >> b;

    ll left = max((ll)pow(a/(2*b), 2.0/3.0) - 1, 0LL);
    ll right = left + 1;
    long double al = left * b + a / sqrt(left + 1);
    long double ar = right * b + a / sqrt(right + 1);

    cout << fixed << setprecision(15) << min(al, ar) << endl;

    return 0;
}