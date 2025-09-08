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

    ll sqrn = (ll)sqrt((double)n) + 1LL;

    // p^8 or p^2・q^2
    vector<ll> primes;
    vector<bool> isPrime(sqrn + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (ll i = 2; i <= sqrn; ++i) {
        if (!isPrime[i]) continue;
        primes.push_back(i);
        for (ll j = 2 * i; j <= sqrn; j += i) {
            isPrime[j] = false;
        }
    }
  
    ll ans = 0;

    // p^8
    for (const ll p : primes) {
        ll m = p * p * p * p * p * p * p * p;
        if (m <= n) {
            ++ans;
        } else {
            break;
        }
    }
    // p^2・q^2
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i + 1; j < primes.size(); ++j) {
            if (primes[i] * primes[j] > sqrn) break;
            ll m = primes[i] * primes[i] * primes[j] * primes[j];
            if (m <= n) {
                ++ans;
            } else {
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}