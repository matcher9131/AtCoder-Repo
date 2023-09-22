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
    int n;
    cin >> n;

    auto isValid = [&](int bit) {
        int lv = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (bit & (1 << i)) {
                --lv;
                if (lv < 0) return false;
            } else {
                ++lv;
            }
        }
        return lv == 0;
    };

    for (int bit = 0; bit < (1 << n); ++bit) {
        if (isValid(bit)) {
            string s;
            for (int i = n - 1; i >= 0; --i) {
                s += (bit & (1 << i)) ? ')' : '(';
            }
            cout << s << endl;
        }
    }

    return 0;
}