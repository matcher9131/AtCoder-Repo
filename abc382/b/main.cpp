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
    int n, d;
    string s;
    cin >> n >> d >> s;

    for (int i = 0; i < d; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[j] == '@') {
                s[j] = '.';
                break;
            }
        }
    }

    cout << s << endl;

    return 0;
}