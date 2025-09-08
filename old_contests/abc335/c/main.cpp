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
    int n, nq;
    cin >> n >> nq;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        p[i].first = i + 1;
    }
    int head = 0;

    while (nq--) {
        int k;
        cin >> k;
        if (k == 1) {
            char c;
            cin >> c;
            auto [tx, ty] = p[head];
            --head;
            if (head < 0) head += n;
            switch (c) {
                case 'R': p[head] = { tx + 1, ty }; break;
                case 'L': p[head] = { tx - 1, ty }; break;
                case 'U': p[head] = { tx, ty + 1 }; break;
                case 'D': p[head] = { tx, ty - 1 }; break;
                break;
            }
        } else {
            int i;
            cin >> i;
            --i;
            auto [x, y] = p[(head + i) % n];
            cout << x << " " << y << endl;
        }
    }

    return 0;
}