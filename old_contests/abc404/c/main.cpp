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
#include <atcoder/dsu>
using namespace std;
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    if (n != m) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> deg(n);
    atcoder::dsu d(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        ++deg[a];
        ++deg[b];
        d.merge(a, b);
    }

    if ((int)d.groups().size() != 1) {
        cout << "No" << endl;
        return 0;
    }

    if (any_of(deg.begin(), deg.end(), [](int x) { return x != 2; })) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}