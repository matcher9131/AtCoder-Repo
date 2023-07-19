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
    ll h, w;
    cin >> h >> w;
    
    if (h % 3 == 0 || w % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll min = std::min(h, w);
    for (int i = 1; i < h; ++i) {
        ll s1 = i * w;
        ll s2 = (h - i) * (w / 2);
        ll s3 = (h - i) * ((w + 1) / 2);
        ll m = max(max(abs(s1 - s2), abs(s1- s3)), abs(s2 - s3));
        if (m < min) min = m;
    }
    for (int j = 1; j < w; ++j) {
        ll s1 = j * h;
        ll s2 = (w - j) * (h / 2);
        ll s3 = (w - j) * ((h + 1) / 2);
        ll m = max(max(abs(s1 - s2), abs(s1- s3)), abs(s2 - s3));
        if (m < min) min = m;
    }
    
    cout << min << endl;

    return 0;
}