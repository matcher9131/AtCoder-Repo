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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;


int main() {
    int n, d;
    cin >> n >> d;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    auto allFree = [&](int j) {
        for (int i = 0; i < n; ++i) {
            if (s[i][j] == 'x') return false;
        }
        return true;
    };

    int max = 0;
    int current = 0;
    for (int j = 0; j < d; ++j) {
        if (allFree(j)) {
            ++current;
            if (current > max) max = current;
        } else {
            current = 0;
        }
    }
    if (current > max) max = current;

    cout << max << endl;

    return 0;
}