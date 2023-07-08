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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;


int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> m(n);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        m[i] = make_pair(a, b);
    }
    sort(m.begin(), m.end(), greater<pair<ll, ll>>());

    ll sum = 0;
    for (const auto& p : m) {
        sum += p.second;
        if (sum > k) {
            cout << p.first + 1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    
    return 0;
}