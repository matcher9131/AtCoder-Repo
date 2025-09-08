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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '#') continue;

            vector<vector<bool>> visited(h, vector<bool>(w));
            visited[i][j] = true;

            function<void(int, int, int)> search = [&](int ni, int nj, int rest) {
                if (rest == 0) {
                    ++ans;
                    return;
                }
                visited[ni][nj] = true;
                if (ni > 0 && s[ni-1][nj] == '.' && !visited[ni-1][nj]) {
                    search(ni-1, nj, rest-1);
                }
                if (ni < h - 1 && s[ni+1][nj] == '.' && !visited[ni+1][nj]) {
                    search(ni+1, nj, rest-1);
                }
                if (nj > 0 && s[ni][nj-1] == '.' && !visited[ni][nj-1]) {
                    search(ni, nj-1, rest-1);
                }
                if (nj < w - 1 && s[ni][nj+1] == '.' && !visited[ni][nj+1]) {
                    search(ni, nj+1, rest-1);
                }
                visited[ni][nj] = false;
            };

            search(i, j, k);
        }
    }

    cout << ans << endl;

    return 0;
}