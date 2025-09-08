#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
using int64 = long long;

int main() {
    int n;
    cin >> n;
    vector<tuple<int64, int64, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        int64 a, b;
        cin >> a >> b;
        p[i] = make_tuple(a, b, i + 1);
    }

    sort(p.begin(), p.end(), [](auto& x, auto& y) {
        int64 xa = get<0>(x), xb = get<1>(x), ya = get<0>(y), yb = get<1>(y);
        int64 r = xa * (ya + yb) - ya * (xa + xb);
        return r == 0 ? get<2>(x) < get<2>(y) : r > 0;
    });

    cout << get<2>(p[0]);
    for (int i = 1; i < n; i++)
    {
        cout << " " << get<2>(p[i]);
    }
    cout << endl;
    
    return 0;
}