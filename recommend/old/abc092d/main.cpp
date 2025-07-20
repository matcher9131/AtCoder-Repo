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
    int a, b;
    cin >> a >> b;

    int h = 46, w = 99;
    vector<string> s(h);
    for (int i = 0; i < h/2; ++i) {
        s[i] = string(w, '.');
    }
    for (int i = h/2; i < h; ++i) {
        s[i] = string(w, '#');
    }

    --a;
    --b;
    for (int i = 0; i < a; ++i) {
        int r = h/2 + 2*(i/49) + 1;
        int c = 2*(i%49) + 1;
        s[r][c] = '.';
    }
    for (int i = 0; i < b; ++i) {
        int r = 2*(i/49) + 1;
        int c = 2*(i%49) + 1;
        s[r][c] = '#';
    }
    
    cout << h << " " << w << endl;
    for (int i = 0; i < h; ++i) {
        cout << s[i] << endl;
    }

    return 0;
}