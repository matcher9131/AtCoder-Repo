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
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    vector<vector<vector<int>>> a(100, vector<vector<int>>(100, vector<int>(100)));
    vector<tuple<int, int, int, int, int, int>> c(n);
    for (int i = 0; i < n; ++i) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        c[i] = make_tuple(x1, y1, z1, x2, y2, z2);
        for (int x = x1; x < x2; ++x) {
            for (int y = y1; y < y2; ++y) {
                for (int z = z1; z < z2; ++z) {
                    a[x][y][z] = i + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        auto [x1, y1, z1, x2, y2, z2] = c[i];
        unordered_set<int> s;
        if (x1 > 0) {
            for (int y = y1; y < y2; ++y) {
                for (int z = z1; z < z2; ++z) {
                    s.insert(a[x1 - 1][y][z]);
                }
            }
        }
        if (x2 < 100) {
            for (int y = y1; y < y2; ++y) {
                for (int z = z1; z < z2; ++z) {
                    s.insert(a[x2][y][z]);
                }
            }
        }
        if (y1 > 0) {
            for (int x = x1; x < x2; ++x) {
                for (int z = z1; z < z2; ++z) {
                    s.insert(a[x][y1 - 1][z]);
                }
            }
        }
        if (y2 < 100) {
            for (int x = x1; x < x2; ++x) {
                for (int z = z1; z < z2; ++z) {
                    s.insert(a[x][y2][z]);
                }
            }
        }
        if (z1 > 0) {
            for (int x = x1; x < x2; ++x) {
                for (int y = y1; y < y2; ++y) {
                    s.insert(a[x][y][z1 - 1]);
                }
            }
        }
        if (z2 < 100) {
            for (int x = x1; x < x2; ++x) {
                for (int y = y1; y < y2; ++y) {
                    s.insert(a[x][y][z2]);
                }
            }
        }
        s.erase(0);
        cout << s.size() << endl;
    }

    return 0;
}