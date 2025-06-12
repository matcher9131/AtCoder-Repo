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
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    vector<int> numOne(30);
    for (int bit = 0; bit < 30; ++bit) {
        for (int i = 0; i < n; ++i) {
            if (a[i] & (1LL << bit)) ++numOne[bit];
        }
    }

    vector<ll> score(n);
    for (int i = 0; i < n; ++i) {
        for (int bit = 0; bit < 30; ++bit) {
            score[i] += (a[i] & (1LL << bit)) * (n - 2 * numOne[bit]);
        }
    }
    int j = max_element(score.begin(), score.end()) - score.begin();

    ll sum2 = 0;
    for (int i = 0; i < n; ++i) {
        sum2 += a[i] ^ a[j];
    }

    cout << max(sum, sum2) << endl;

    return 0;
}