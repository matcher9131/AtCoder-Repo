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
using namespace std;
using ll = long long;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> reply(n);
    for (int i = 0; i < k + 1; ++i) {
        cout << "?";
        for (int j = 0; j < k + 1; ++j) {
            if (i == j) continue;
            cout << " " << j + 1;
        }
        cout << endl;
        cin >> reply[i];
    }
    for (int i = k + 1; i < n; ++i) {
        cout << "? " << i + 1;
        for (int j = 0; j < k - 1; ++j) {
            cout << " " << j + 1;
        }
        cout << endl;
        cin >> reply[i];
    }

    vector<int> a(n);
    int skp1 = accumulate(reply.begin(), reply.begin() + k + 1, 0) % 2;
    for (int i = 0; i < k + 1; ++i) {
        a[i] = (skp1 - reply[i] + 2) % 2;
    }
    int skm1 = accumulate(reply.begin(), reply.begin() + (k - 1), 0) % 2;
    for (int i = k + 1; i < n; ++i) {
        a[i] = (reply[i] - skm1 + 2) % 2;
    }

    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << a[i];
    }
    cout << endl;

    return 0;
}