#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
#include <functional>
#include <atcoder/segtree>
using namespace std;
using ll = long long;

using S = ll;
S op(S a, S b) {
    return a + b;
}
S e() {
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto forceSumToBePositive = [&](atcoder::segtree<S, op, e> &seg, int i) -> ll {
        ll count = 0;
        ll sum = seg.prod(0, i+1);
        if (sum <= 0) {
            if (i > 0) {
                ll prevSum = seg.prod(0, i);
                ll d = min(-1 - prevSum, 1 - sum);
                count += d;
                seg.set(i-1, seg.get(i-1) + d);
                sum += d;
            }
            if (sum <= 0) {
                ll d = 1 - sum;
                count += d;
                seg.set(i, seg.get(i) + d);
            }
        }
        return count;
    };
    auto forceSumToBeNegative = [&](atcoder::segtree<S, op, e> &seg, int i) -> ll {
        ll count = 0;
        ll sum = seg.prod(0, i+1);
        if (sum >= 0) {
            if (i > 0) {
                ll prevSum = seg.prod(0, i);
                ll d = min(prevSum - 1, sum - (-1));
                count += d;
                seg.set(i-1, seg.get(i-1) - d);
                sum -= d;
            }
            if (sum >= 0) {
                ll d = sum - (-1);
                count += d;
                seg.set(i, seg.get(i) - d);
            }
        }
        return count;
    };

    atcoder::segtree<S, op, e> pSeg(a);
    atcoder::segtree<S, op, e> nSeg(a);
    ll pAns = 0, nAns = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2) {
            pAns += forceSumToBePositive(pSeg, i);
            nAns += forceSumToBeNegative(nSeg, i);
        } else {
            pAns += forceSumToBeNegative(pSeg, i);
            nAns += forceSumToBePositive(nSeg, i);
        }
    }

    cout << min(pAns, nAns) << endl;

    return 0;
}