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
#include <atcoder/modint>
using namespace std;
using ll = long long;

using mint = atcoder::modint1000000007;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    mint answer = 0;
    mint c = 1;
    answer += c * a[k - 1];
    answer -= c * a[n - k];
    for (int i = k + 1; i <= n; ++i) {
        c *= i - 1;
        c /= i - k;
        answer += c * a[i - 1];
        answer -= c * a[n - i];
    }

    cout << answer.val() << endl;

    return 0;
}