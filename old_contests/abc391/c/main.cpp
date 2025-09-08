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
    vector<int> p(n), numPegion(n, 1);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    int ans = 0;
    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            int pi, to;
            cin >> pi >> to;
            --pi;
            --to;
            int from = p[pi];
            if (numPegion[from] == 2) {
                --ans;
            }
            --numPegion[from];
            ++numPegion[to];
            p[pi] = to;
            if (numPegion[to] == 2) {
                ++ans;
            }
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}