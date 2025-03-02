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
    vector<int> nest(n), pegion(n);
    unordered_map<int, int> nestLookup;
    for (int i = 0; i < n; ++i) {
        nest[i] = i;
        pegion[i] = i;
        nestLookup[i] = i;
    }

    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            pegion[a] = nest[b];
        } else if (k == 2) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            int x = nest[a];
            int y = nest[b];
            swap(nest[a], nest[b]);
            nestLookup[y] = a;
            nestLookup[x] = b;
        } else {
            int a;
            cin >> a;
            --a;
            cout << nestLookup[pegion[a]] + 1 << endl;
        }
    }

    return 0;
}