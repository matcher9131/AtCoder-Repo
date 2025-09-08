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
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;

constexpr ll M = 1e9;

int main() {
    int n, k;
    cin >> n >> k;

    atcoder::fenwick_tree<ll> a(max(n + 1, k + 1));
    for (int i = 0; i < k; ++i) {
        a.add(i, 1);
    }
    for (int i = k; i < n + 1; ++i) {
        a.add(i, a.sum(i - k, i) % M);
    }

    cout << a.sum(n, n + 1) << endl;
    return 0;
}