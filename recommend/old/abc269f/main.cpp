#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll h, w, nq;
    cin >> h >> w >> nq;

    while (nq--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        --a;
        --b;
        --c;
        --d;
        ll eLeft = c%2 ? c+1 : c;
        ll eRight = d%2 ? d-1 : d;
        mint eColCount = eLeft <= eRight ? (eRight - eLeft) / 2 + 1 : 0;
        ll eTop = a%2 ? a+1 : a;
        ll eBottom = b%2 ? b-1 : b;
        mint eRowCount = eTop <= eBottom ? (eBottom - eTop) / 2 + 1 : 0;
        ll oLeft = c%2 ? c : c+1;
        ll oRight = d%2 ? d : d-1;
        mint oColCount = oLeft <= oRight ? (oRight - oLeft) / 2 + 1 : 0;
        ll oTop = a%2 ? a : a+1;
        ll oBottom = b%2 ? b : b-1;
        mint oRowCount = oTop <= oBottom ? (oBottom - oTop) / 2 + 1 : 0;
        // 最上行の和: 初項(top, left), 末項(top, right), 項数colCountの等差数列の和
        mint eSum = ((mint)eTop * w + eLeft + 1 + (mint)eTop * w + eRight + 1) * eColCount / 2;
        mint oSum = ((mint)oTop * w + oLeft + 1 + (mint)oTop * w + oRight + 1) * oColCount / 2;
        // 和: 初項sum, 公差2*w*colCount, 項数rowCountの等差数列の和
        mint eAns = (2 * eSum + (eRowCount - 1) * 2 * w * eColCount) * eRowCount / 2;
        mint oAns = (2 * oSum + (oRowCount - 1) * 2 * w * oColCount) * oRowCount / 2;
        cout << (eAns + oAns).val() << endl;
    }

    return 0;
}