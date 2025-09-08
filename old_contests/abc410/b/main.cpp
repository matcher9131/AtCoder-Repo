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
    vector<int> x(nq);
    for (int i = 0; i < nq; ++i) {
        cin >> x[i];
        --x[i];
    }

    vector<int> a(n);
    for (int i = 0; i < nq; ++i) {
        if (x[i] == -1) {
            auto it = min_element(a.begin(), a.end());
            *it += 1;
            x[i] = it - a.begin();
        } else {
            ++a[x[i]];
        }
    }

    for (int i = 0; i < nq; ++i) {
        cout << x[i] + 1 << " \n"[i == nq - 1];
    }

    return 0;
}