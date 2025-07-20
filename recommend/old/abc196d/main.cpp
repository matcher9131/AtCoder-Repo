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
#include <bitset>
using namespace std;
using ll = long long;

int h, w, na, nb, answer = 0;


void dfs(int i, int bit, int a, int b) {
    if (i == h * w) {
        ++answer;
        return;
    }

    if ((bit & 1 << i)) {
        dfs(i + 1, bit, a, b);
        return;
    }
    int x = i % w;
    int y = i / w;
    if (a < na && x < w - 1 && (bit & 1 << (i + 1)) == 0) {
        dfs(i + 2, bit | 1 << i | 1 << (i + 1), a + 1, b);
    }
    if (a < na && y < h - 1 && (bit & 1 << (i + w)) == 0) {
        dfs(i + 1, bit | 1 << i | 1 << (i + w), a + 1, b);
    }
    if (b < nb) {
        dfs(i + 1, bit | 1 << i, a, b + 1);
    }
}


int main() {
    cin >> h >> w >> na >> nb;

    dfs(0, 0, 0, 0);

    cout << answer << endl;

    return 0;
}