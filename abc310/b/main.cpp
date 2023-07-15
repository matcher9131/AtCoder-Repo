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
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<vector<bool>> f(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> p[i] >> c;
        for (int ci = 0; ci < c; ++ci) {
            int mi;
            cin >> mi;
            --mi;
            f[i][mi] = true;
        }
    }
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (p[i] == p[j]) {
                bool iSuperiors = false, jSuperiors = false;
                for (int mi = 0; mi < m; ++mi) {
                    if (f[i][mi] && !f[j][mi]) {
                        iSuperiors = true;
                    } else if (!f[i][mi] && f[j][mi]) {
                        jSuperiors = true;
                    }
                }
                if (iSuperiors ^ jSuperiors) {
                    cout << "Yes" << endl;
                    return 0;
                }
            } else {
                int li = p[i] < p[j] ? i : j;
                int hi = p[i] < p[j] ? j : i;
                bool superiors = true;
                for (int mi = 0; mi < m; ++mi) {
                    if (!f[li][mi] && f[hi][mi]) {
                        superiors = false;
                        break;
                    }
                }
                if (superiors) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}