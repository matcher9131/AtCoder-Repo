#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
#include <cmath>
#include <climits>
#include <numeric>
using namespace std;
using int64 = long long;

struct ratio {
    int64 n;
    int64 d;
};

ratio createRatio(int64 n, int64 d) {
    int64 g = gcd(d, n);
    return { n / g, d / g };
}
ratio add(const ratio& x, const ratio& y) {
    int64 n = x.n * y.d + x.d * y.n;
    int64 d = x.d * y.d;
    int64 g = gcd(d, n);
    return { n / g, d / g };
}
ratio subtract(const ratio& x, const ratio& y) {
    int64 n = x.n * y.d - x.d * y.n;
    int64 d = x.d * y.d;
    int64 g = gcd(d, n);
    return { n / g, d / g };
}
ratio multiply(const ratio& x, const ratio& y) {
    int64 g1 = gcd(x.n, y.d);
    int64 g2 = gcd(y.n, x.d);
    return { (x.n / g1) * (y.n / g2), (x.d / g2) * (y.d / g1) };
}
ratio divide(const ratio& x, const ratio& y) {
    int64 g1 = gcd(x.n, y.n);
    int64 g2 = gcd(x.d, y.d);
    int64 sign = y.n < 0 ? -1 : 1;
    return { sign * (x.n / g1) * (y.d / g2), sign * (x.d / g2) * (y.n / g1) };
}
void showRatio(const ratio& r) {
    cout << r.n << "/" << r.d << endl;
}

vector<int64> search(vector<int64> a, ratio rest, int restCount) {
    if (restCount == 1) {
        if (rest.n == 1) {
            a.push_back(rest.d);
            return a;
        }
    } else if (rest.n > 0) {
        ratio r = divide({restCount, 1}, rest);
        int64 max = r.n / r.d;
        ratio r2 = subtract({1, 1}, rest);
        int64 min = r2.n / r2.d;
        if (min < 2) min = 2;
        for (int64 i = min; i <= max; ++i) {
            vector<int64> b = a;
            b.push_back(i);
            vector<int64> nextA = search(b, subtract(rest, {1, i}), restCount - 1);
            if (!nextA.empty()) return nextA;
        }
    }
    return vector<int64>();
}

void judge(int64 n) {
    auto result = search(vector<int64>(), {1, 1}, n);
    if (result.empty()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << result[0];
        for (size_t i = 1; i < result.size(); i++)
        {
            cout << " " << result[i];
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        judge(n);
    }

    return 0;
}