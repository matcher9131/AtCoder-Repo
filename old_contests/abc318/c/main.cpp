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
using namespace std;
using ll = long long;

int main() {
    int n, d;
    ll p;
    cin >> n >> d >> p;
    vector<ll> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    sort(f.begin(), f.end(), greater<ll>());

    auto sumd = [&](int startIndex) {
        ll sum = 0;
        for (int i = startIndex; i < min(n, startIndex + d); ++i) {
            sum += f[i];
        }
        return sum;
    };

    ll answer = 0;
    for (int i = 0; i < n; i += d) {
        ll s = sumd(i);
        answer += min(s, p);
    }
    
    cout << answer << endl;

    return 0;
}
