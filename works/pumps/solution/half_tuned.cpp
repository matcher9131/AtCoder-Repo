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

    ull full = bitMax - 1;
    ull colL = 0, colR = 0;
    for (ll i = 0; i < hh; ++i) {
        colL |= 1ULL << (i*w);
        colR |= 1ULL << (i*w + w-1);
    }
    ull notL = full & ~colL, notR = full & ~colR;

    for (ull bit = 0; bit < bitMax; ++bit) {
        //
        if (bit % 100000000ULL == 0) cout << "bit = " << bit << endl;
        //
        ull bL = bit & notL, bR = bit & notR;
        ull nb = ~bit & full;
        ll cnt = popcount((bR << 1) & nb)       // E
               + popcount((bL >> 1) & nb)       // W
               + popcount((bit << w) & nb)      // S
               + popcount((bit >> w) & nb)      // N
               + popcount((bR << (w+1)) & nb)   // SE
               + popcount((bL << (w-1)) & nb)   // SW
               + popcount((bR >> (w-1)) & nb)   // NE
               + popcount((bL >> (w+1)) & nb);  // NW
        ll sum = a * popcount(bit) + b * cnt;
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