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

tuple<bool, int, int> intersect1D(int l1, int r1, int l2, int r2) {
    if (l1 > l2) return intersect1D(l2, r2, l1, r1);
    if (l2 < r1) return {true, l2, min(r1, r2)};
    return {false, 0, 0};
}

tuple<bool, int, int, int, int, int, int> intersect3D(int a1l, int b1l, int c1l, int a1r, int b1r, int c1r, int a2l, int b2l, int c2l, int a2r, int b2r, int c2r) {
    auto [ix, xl, xr] = intersect1D(a1l, a1r, a2l, a2r);
    if (!ix) return { false, 0, 0, 0, 0, 0, 0 };
    auto [iy, yl, yr] = intersect1D(b1l, b1r, b2l, b2r);
    if (!iy) return { false, 0, 0, 0, 0, 0, 0 };
    auto [iz, zl, zr] = intersect1D(c1l, c1r, c2l, c2r);
    if (!iz) return { false, 0, 0, 0, 0, 0, 0 };
    return { true, xl, yl, zl, xr, yr, zr };
}

int main() {
    int u1, u2, u3;
    cin >> u1 >> u2 >> u3;

    for (int a2 = 0; a2 <= 7; ++a2) {
        for (int b2 = 0; b2 <= 7; ++b2) {
            for (int c2 = 0; c2 <= 7; ++c2) {
                for (int a3 = -7; a3 <= 7; ++a3) {
                    for (int b3 = -7; b3 <= 7; ++b3) {
                        for (int c3 = -7; c3 <= 7; ++c3) {
                            auto [i12, x12l, y12l, z12l, x12r, y12r, z12r] = intersect3D(0, 0, 0, 7, 7, 7, a2, b2, c2, a2+7, b2+7, c2+7);
                            auto [i23, x23l, y23l, z23l, x23r, y23r, z23r] = intersect3D(a2, b2, c2, a2+7, b2+7, c2+7, a3, b3, c3, a3+7, b3+7, c3+7);
                            auto [i31, x31l, y31l, z31l, x31r, y31r, z31r] = intersect3D(a3, b3, c3, a3+7, b3+7, c3+7, 0, 0, 0, 7, 7, 7);
                            int v12 = (x12r - x12l) * (y12r - y12l) * (z12r - z12l);
                            int v23 = (x23r - x23l) * (y23r - y23l) * (z23r - z23l);
                            int v31 = (x31r - x31l) * (y31r - y31l) * (z31r - z31l);
                            int v123 = 0;
                            if (i12) {
                                auto [i123, x123l, y123l, z123l, x123r, y123r, z123r] = intersect3D(x12l, y12l, z12l, x12r, y12r, z12r, a3, b3, c3, a3+7, b3+7, c3+7);
                                v123 = (x123r - x123l) * (y123r - y123l) * (z123r - z123l);
                            }
                            if (v123 == u3 && v12 + v23 + v31 - 3 * v123 == u2 && 1029 - 2 * v12 - 2 * v23 - 2 * v31 + 3 * v123 == u1) {
                                cout << "Yes" << endl;
                                printf("0 0 0 %d %d %d %d %d %d\n", a2, b2, c2, a3, b3, c3);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}