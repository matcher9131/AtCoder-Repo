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
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    --x;
    --y;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    string t;
    cin >> t;

    int c = 0;    
    for (size_t i = 0; i < t.length(); ++i) {
        bool moved = false;
        switch (t[i]) {
            case 'U':
                if (s[x-1][y] != '#') {
                    moved = true;
                    --x;
                }
                break;
            case 'D':
                if (s[x+1][y] != '#') {
                    moved = true;
                    ++x;
                }
                break;
            case 'L':
                if (s[x][y-1] != '#') {
                    moved = true;
                    --y;
                }
                break;
            case 'R':
                if (s[x][y+1] != '#') {
                    moved = true;
                    ++y;
                }
                break;
            default:
                break;
        }
        if (moved && s[x][y] == '@') {
            ++c;
            s[x][y] = '.';
        }
    }
    
    cout << x + 1 << " " << y + 1 << " " << c << endl;

    return 0;
}