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
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    auto getScore = [&](int bits) {
        int score = 0;
        if (bits & 1) score += e;
        if (bits & 2) score += d;
        if (bits & 4) score += c;
        if (bits & 8) score += b;
        if (bits & 16) score += a;
        return score;
    };

    auto getName = [](int bits) {
        string str = "";
        if (bits & 16) str += "A";
        if (bits & 8) str += "B";
        if (bits & 4) str += "C";
        if (bits & 2) str += "D";
        if (bits & 1) str += "E";
        return str;
    };

    auto compare = [&](int x, int y) {
        int sx = getScore(x);
        int sy = getScore(y);
        return sx == sy ? getName(x) < getName(y) : sx > sy;
    };

    set<int, decltype(compare)> s(compare);
    // 上位ビットから順にA,B,...,Eに対応
    for (int i = 1; i < 32; ++i) {
        s.insert(i);
    }

    for (const int i : s) {
        cout << getName(i) << endl;
    }

    return 0;
}