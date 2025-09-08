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
    vector<int> a(nq);
    for (int i = 0; i < nq; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<bool> t(n, true);
    for (const int ai : a) {
        t[ai] = !t[ai];
    }

    cout << count(t.begin(), t.end(), true) << endl;

    return 0;
}