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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i+1;
    }

    int start = 0;
    while (nq--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            a[(start + p) % n] = x;
        } else if (type == 2) {
            int p;
            cin >> p;
            --p;
            cout << a[(start + p) % n] << endl;
        } else {
            int k;
            cin >> k;
            start += k;
            start %= n;
        }
    }

    return 0;
}