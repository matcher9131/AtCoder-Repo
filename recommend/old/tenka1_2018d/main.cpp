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
    ll n;
    cin >> n;

    ll k = sqrt(2*n) + 1;
    if (k * (k-1) / 2 != n) {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<ll>> s(k);
    for (ll i = 0; i < (k-1)/2; ++i) {
        for (ll j = 0; j < k; ++j) {
            ll ei = i * k + j;
            s[j].push_back(ei);
            s[(j + i + 1) % k].push_back(ei);
        }
    }
    if (k % 2 == 0) {
        for (ll i = 0; i < k/2; ++i) {
            s[i].push_back(k * (k/2 - 1) + i);
            s[i+k/2].push_back(k * (k/2 - 1) + i);
        }
    }

    cout << "Yes" << endl;
    cout << k << endl;
    for (ll i = 0; i < k; ++i) {
        cout << s[i].size() << " ";
        for (ll j = 0; j < (ll)s[i].size(); ++j) {
            cout << s[i][j] + 1 << " \n"[j == (ll)s[i].size() - 1];
        }
    }
    return 0;
}