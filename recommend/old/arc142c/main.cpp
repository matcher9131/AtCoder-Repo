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

constexpr int INF = 1000;

int main() {
    int n;
    cin >> n;
    vector<int> d1(n, INF), d2(n, INF);

    for (int i = 2; i < n; ++i) {
        int d1i, d2i;
        cout << "? 1 " << i + 1 << endl;
        cin >> d1i;
        if (d1i == -1) exit(1);
        d1[i] = d1i;
        cout << "? 2 " << i + 1 << endl;
        cin >> d2i;
        if (d2i == -1) exit(1);
        d2[i] = d2i;
    }

    int d1min = *min_element(d1.begin(), d1.end());
    int d2min = *min_element(d2.begin(), d2.end());
    if (d1min == 2 || d2min == 2) {
        cout << "! 1" << endl;
        return 0;
    }

    int d1u = INF, d2v = INF, u = -1, v = -1;
    for (int i = 2; i < n; ++i) {
        if (d1[i] > 1) continue;
        if (d2[i] < d2v) {
            d2v = d2[i];
            v = i;
        }
    }
    for (int i = 2; i < n; ++i) {
        if (d2[i] > 1) continue;
        if (d1[i] < d1u) {
            d1u = d1[i];
            u = i;
        }
    }

    if (d2v == 2) {
        int uv;
        cout << "? " << v + 1 << " " << u + 1 << endl;
        cin >> uv;
        if (uv == -1) exit(1);
        cout << "! " << (uv == 3 ? 1 : 3) << endl;
    } else {
        cout << "! " << d2v + 1 << endl;
    }

    return 0;
}