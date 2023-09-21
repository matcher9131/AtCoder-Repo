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
    vector<vector<int>> a(n, vector<int>(n));

    if (n % 2 == 0) {
        // e e e e
        // e e e e
        // o o o o
        // o o o o
        for (int i = 0; i < n * n / 2; ++i) {
            a[i / n][i % n] = 2 * (i + 1);
        }
        int r = (a[n / 2 - 1][0] + n * n - 1) % 3;
        int offset = r == 0 ? 0
            : r == 1 ? -4
            : -2;
        for (int i = 0; i < n * n / 2; ++i) {
            a[i / n + n / 2][i % n] = (n * n - 1 - 2 * i + offset + n * n) % (n * n);
        }
    } else {
        // e e e e e
        // e e e e e
        // e e o o o
        // o o o o o
        // o o o o o
        for (int i = 0; i < n * n / 2; ++i) {
            a[i / n][i % n] = 2 * (i + 1);
        }
        int cl = n * n / 2 - 1;
        int cu = n * n / 2 - n;
        swap(a[(cl - 3) / n][(cl - 3) % n], a[cu / n][cu % n]);

        set<int, greater<int>> s;
        for (int i = 0; i <= n * n / 2; ++i) {
            s.emplace_hint(s.begin(), 2 * i + 1);
        }

        for (const int i : s) {
            if ((a[n / 2 - 1][n / 2] + i) % 3 == 0 && a[n / 2 - 1][n / 2] + i > 3) {
                a[n / 2][n / 2] = i;
                s.erase(i);
                break;
            }
        }

        for (int x = 0; x < n; ++x) {
            if (x == n / 2) continue;
            int y = n / 2 + (x < n / 2 ? 1 : 0);
            for (const int i : s) {
                if ((a[y - 1][x] + i) % 3 == 0 && a[y - 1][x] + i > 3) {
                    a[y][x] = i;
                    s.erase(i);
                    break;
                }
            }
        }

        int i = 0;
        for (const int j : s) {
            a[(n * n - 1 - i) / n][(n * n - 1 - i) % n] = j;
            ++i;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i][0];
        for (int j = 1; j < n; ++j) {
            cout << " " << a[i][j];
        }
        cout << endl;
    }

    return 0;
}