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
    vector<char> c(n);
    vector<ll> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> l[i];
        if (l[i] > 100) {
            cout << "Too Long" << endl;
            return 0;
        }
    }

    string s = "";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l[i]; ++j) {
            s += c[i];
        }
        if ((int)s.size() > 100) {
            cout << "Too Long" << endl;
            return 0;
        }
    }    

    cout << s << endl;

    return 0;
}