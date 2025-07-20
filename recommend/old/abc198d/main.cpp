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
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <sstream>
using namespace std;
using ll = long long;

ll fillNumber(const string& s, const unordered_map<char, ll>& map, const vector<ll>& digits) {
    ll n = 0;
    for (int i = 0; i < s.size(); ++i) {
        n = 10 * n + digits[map.at(s[i])];
    }
    return n;
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<char> heads{ s1[0], s2[0], s3[0] };
    vector<char> chars;
    for (const char c : s1) {
        if (find(chars.begin(), chars.end(), c) == chars.end()) {
            chars.push_back(c);
        }
    }
    for (const char c : s2) {
        if (find(chars.begin(), chars.end(), c) == chars.end()) {
            chars.push_back(c);
        }
    }
    for (const char c : s3) {
        if (find(chars.begin(), chars.end(), c) == chars.end()) {
            chars.push_back(c);
        }
    }
    int cn = chars.size();

    unordered_map<char, ll> map;
    for (int i = 0; i < cn; ++i) {
        map.emplace(chars[i], i);
    }
    if (map.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vector<ll> digits { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    auto headIsZero = [&]() {
        for (const char head : heads) {
            if (digits[map[head]] == 0) return true;
        }
        return false;
    };

    ll n1 = -1, n2 = -1, n3 = -1;
    do {
        if (headIsZero()) continue;
        n1 = fillNumber(s1, map, digits);
        n2 = fillNumber(s2, map, digits);
        n3 = fillNumber(s3, map, digits);
        
        if (n3 == n1 + n2) break;
    } while (next_permutation(digits.begin(), digits.end()));

    if (n3 == n1 + n2 && n3 > 0) {
        cout << n1 << endl;
        cout << n2 << endl;
        cout << n3 << endl;
    } else {
        cout << "UNSOLVABLE" << endl;
    }

    return 0;
}