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
    int ha, wa;
    cin >> ha >> wa;
    vector<string> a(ha);
    for (int i = 0; i < ha; ++i) {
        cin >> a[i];
    }
    int hb, wb;
    cin >> hb >> wb;
    vector<string> b(hb);
    for (int i = 0; i < hb; ++i) {
        cin >> b[i];
    }
    int hx, wx;
    cin >> hx >> wx;
    vector<string> x(hx);
    for (int i = 0; i < hx; ++i) {
        cin >> x[i];
    } 

    for (int ia = -9; ia <= 9; ++ia) {
        for (int ja = -9; ja <= 9; ++ja) {
            for (int ib = -9; ib <= 9; ++ib) {
                for (int jb = -9; jb <= 9; ++jb) {
                    vector<string> y(30, string(30, '.'));
                    int u = 100, d = 0, l = 100, r = 0;
                    // シートAを(10+ia,10+ja)におく
                    for (int i = 0; i < ha; ++i) {
                        for (int j = 0; j < wa; ++j) {
                            if (a[i][j] == '#') {
                                y[10+ia+i][10+ja+j] = '#';
                                u = min(u, 10+ia+i);
                                d = max(d, 10+ia+i);
                                l = min(l, 10+ja+j);
                                r = max(r, 10+ja+j);
                            }
                        }
                    }
                    // シートBを(10+ib, 10+jb)におく
                    for (int i = 0; i < hb; ++i) {
                        for (int j = 0; j < wb; ++j) {
                            if (b[i][j] == '#') {
                                y[10+ib+i][10+jb+j] = '#';
                                u = min(u, 10+ib+i);
                                d = max(d, 10+ib+i);
                                l = min(l, 10+jb+j);
                                r = max(r, 10+jb+j);
                            }
                        }
                    }
                    // 幅チェック
                    if (u < 10 || d > 10 + hx - 1 || l < 10 || r > 10 + wx - 1) continue;
                    // 模様チェック
                    auto check = [&](int ix, int jx) -> bool {
                        for (int i = 0; i < hx; ++i) {
                            for (int j = 0; j < wx; ++j) {
                                if (x[i][j] != y[ix+i][jx+j]) return false;
                            }
                        }
                        return true;
                    };
                    if (check(10, 10)) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}