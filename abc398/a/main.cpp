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

    if (n % 2) {
        string s(n, '-');
        s[(n-1)/2] = '=';
        cout << s << endl;
    } else {
        string s(n, '-');
        s[n/2-1] = s[n/2] = '=';
        cout << s << endl;
    }

    return 0;
}