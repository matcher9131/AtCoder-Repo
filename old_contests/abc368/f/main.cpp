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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int aMax = *max_element(a.begin(), a.end());

    vector<int> grundyMap(aMax + 1, 1);
    grundyMap[1] = 0;
    for (int i = 2; i < grundyMap.size(); ++i) {
        vector<bool> gr(100);
        gr[0] = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j > 0) continue;
            gr[grundyMap[j]] = true;
            gr[grundyMap[i / j]] = true;
        }
        for (int gi = 0; gi < gr.size(); ++gi) {
            if (!gr[gi]) {
                grundyMap[i] = gi;
                break;
            }
        }
    }

    int xo = 0;
    for (int i = 0; i < n; ++i) {
        xo ^= grundyMap[a[i]];
    }

    cout << (xo == 0 ? "Bruno" : "Anna") << endl;

    return 0;
}