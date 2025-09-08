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
    int n, nq;
    cin >> n >> nq;
    vector<pair<char, int>> q(nq);
    for (int i = 0; i < nq; ++i) {
        char h;
        int t;
        cin >> h >> t;
        --t;
        q[i] = make_pair(h, t);
    }

    int l = 0, r = 1;
    int ans = 0;
    for (const auto& [h, t] : q) {
        if (h == 'L') {
            if (l < t) {
                if (l < r && r < t) {
                    ans += l + n - t;
                } else {
                    ans += t - l;
                }
            } else if (t < l) {
                if (t < r && r < l) {
                    ans += t + n - l;
                } else {
                    ans += l - t;
                }
            }
            l = t;
        } else {
            if (r < t) {
                if (r < l && l < t) {
                    ans += r + n - t;
                } else {
                    ans += t - r;
                }
            } else if (t < r) {
                if (t < l && l < r) {
                    ans += t + n - r;
                } else {
                    ans += r - t;
                }
            }
            r = t;
        }
    }

    cout << ans << endl;

    return 0;
}