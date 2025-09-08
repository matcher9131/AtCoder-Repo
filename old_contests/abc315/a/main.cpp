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
using namespace std;
using ll = long long;


int main() {
    string s;
    cin >> s;
    string t;

    for (int i = 0; i < s.size(); ++i) {
        switch (s[i]) {
            case 'a':
            case 'i':
            case 'u':
            case 'e':
            case 'o':
                break;
            default: {
                t += s[i];
                break;
            }
        }
    }

    cout << t << endl;

    return 0;
}