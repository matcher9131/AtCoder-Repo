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
using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    string s = "";

    vector<int> j;
    for (int ji = 1; ji < 10; ++ji) {
        if (n % ji == 0) j.push_back(ji);
    }

    for (int i = 0; i <= n; ++i) {
        for (const int ji : j) {
            if (i % (n / ji) == 0) {
                s += (char)(ji + '0');
                break;
            }
        }
        if (s.size() == i) s += '-';
    }

    cout << s << endl;


    return 0;
}
