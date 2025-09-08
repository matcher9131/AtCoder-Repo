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
    int n = 15;
    int max = (int)pow(3, n);

    map<tuple<int, int, int>, vector<int>> m;
    for (int pattern = 0; pattern < max; ++pattern) {
        int p = pattern;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(p % 3);
            p /= 3;
        }
        bool ok = true;
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 2) {
                ++z;
                if (a[(i + n - 1) % n] == 2 || a[(i+1) % n] == 2) {
                    ok = false;
                    break;
                }
            } else if (a[i] == 1) {
                ++y;
                bool b1 = a[(i + n-1) % n] >= 1;
                bool b2 = a[(i+1) % n] >= 1;
                if (b1 == b2) {
                    ok = false;
                    break;
                }
            } else {
                ++x;
            }
        }
        if (ok) {
            m[{x,y,z}] = a;
        }
    }

    for (const auto &[key, value] : m) {
        auto [x,y,z] = key;
        printf("(%d, %d, %d): ", x, y, z);
        for (int i = 0; i < n; ++i) {
            cout << value[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}