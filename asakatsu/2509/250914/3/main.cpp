#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    double a, b, x;
    cin >> a >> b >> x;

    if (x >= a * a * b / 2) {
        cout << setprecision(15) << atan(2 * (a*a*b - x) / (a*a*a)) * 180.0 / acos(-1) << endl;
    } else {
        cout << setprecision(15) << atan(a*b*b/2/x) * 180.0 / acos(-1) << endl;
    }

    return 0;
}