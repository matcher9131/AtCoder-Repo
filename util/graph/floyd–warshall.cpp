#include <vector>
using namespace std;

extern int n;
extern vector<vector<int>> d;

void floyd_warshall(vector<vector<int>> &d) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
