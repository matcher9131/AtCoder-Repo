#include <vector>
using namespace std;
using ll = long long;

extern int n;
extern vector<vector<ll>> d;

void floyd_warshall(vector<vector<ll>> &d) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
