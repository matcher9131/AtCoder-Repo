#include <vector>
using namespace std;
using ll = long long;
extern int n;
extern vector<int> a;

void lis() {
    vector<ll> lis;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if (it == lis.end()) {
            lis.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
}