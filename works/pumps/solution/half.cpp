#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll h, w, a, b;
    cin >> h >> w >> a >> b;

    if (h % 2) return 1;

    ll hh = h / 2;
    ull bitMax = 1ULL << (hh*w);
    ull numDic = 1ULL << w;
    ull rowMask = numDic - 1;
    vector<pair<ll, ull>> dic(numDic);

    for (ull bit = 0; bit < bitMax; ++bit) {
        ll sum = 0;
        for (ll i = 0; i < hh; ++i) {
            for (ll j = 0; j < w; ++j) {
                if (bit & (1ULL << (i*w+j))) {
                    ll c = 0;
                    if (i < hh-1 && (bit & (1ULL << ((i+1)*w+j))) == 0) ++c;
                    if (i < hh-1 && j < w-1 && (bit & (1ULL << ((i+1)*w+j+1))) == 0) ++c;
                    if (i < hh-1 && j > 0 && (bit & (1ULL << ((i+1)*w+j-1))) == 0) ++c;
                    if (i > 0 && (bit & (1ULL << ((i-1)*w+j))) == 0) ++c;
                    if (i > 0 && j < w-1 && (bit & (1ULL << ((i-1)*w+j+1))) == 0) ++c;
                    if (i > 0 && j > 0 && (bit & (1ULL << ((i-1)*w+j-1))) == 0) ++c;
                    if (j < w-1 && (bit & (1ULL << (i*w+j+1))) == 0) ++c; 
                    if (j > 0 && (bit & (1ULL << (i*w+j-1))) == 0) ++c; 
                    sum += a + c * b;
                }
            }
        }
        if (sum > dic[bit & rowMask].first) {
            dic[bit & rowMask].first = sum;
            dic[bit & rowMask].second = bit;
        }
    }

    ll ans = 0;
    ull ansBit = 0;
    for (ull bit1 = 0; bit1 < numDic; ++bit1) {
        for (ull bit2 = 0; bit2 < numDic; ++bit2) {
            ll sum = dic[bit1].first + dic[bit2].first;
            for (ll j = 0; j < w; ++j) {
                if (bit1 & (1ULL << j)) {
                    if (j > 0 && (bit2 & (1ULL << (j-1))) == 0) sum += b;
                    if ((bit2 & (1ULL << j)) == 0) sum += b;
                    if (j < w-1 && (bit2 & (1ULL << (j+1))) == 0) sum += b;
                }
                if (bit2 & (1ULL << j)) {
                    if (j > 0 && (bit1 & (1ULL << (j-1))) == 0) sum += b;
                    if ((bit1 & (1ULL << j)) == 0) sum += b;
                    if (j < w-1 && (bit1 & (1ULL << (j+1))) == 0) sum += b;
                }
            }
            if (sum > ans) {
                ans = sum;
                ansBit = dic[bit1].second << (hh*w);
                for (ll i = 0; i < hh; ++i) {
                    ull row = (dic[bit2].second >> (i*w)) & rowMask;
                    ansBit |= row << ((hh-1 - i) * w);
                }
            }
        }
    }

    cout << ans << endl;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cout << ((ansBit & (1ULL << (i*w+j))) ? '#' : '.');
        }
        cout << endl;
    }

    return 0;
}