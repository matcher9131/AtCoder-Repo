#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;

    ll left = 0;
    ll right = n-1;

    while (abs(right - left) > 1) {
        ll mid = (right + left) / 2;
        cout << "? " << mid+1 << endl;
        char c;
        cin >> c;
        if (c == '1') right = mid;
        else left = mid;
    }

    cout << "! " << left+1 << endl;
    return 0;
}