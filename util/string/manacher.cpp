#include <string>
#include <vector>
using namespace std;

vector<int> manacher(string s) {
    string t(2 * (int)s.size() + 1, '#');
    for (int i = 0; i < (int)s.size(); ++i) {
        t[2*i+1] = s[i];
    }
    int n = t.size();

    vector<int> rad(n);
    int center = 0, r = 0;
    while (center < n) {
        while (0 <= center - r && center + r < n && s[center - r] == s[center + r]) ++r;
        rad[center] = r;

        int k = 1;
        while (0 <= center - k && k + rad[center - k] < r) {
            rad[center + k] = rad[center - k];
            ++k;
        }

        center += k;
        r -= k;
    }

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            rad[i] = (rad[i] - 1) / 2;
        } else {
            rad[i] /= 2;
        }
    }

    return rad;
}