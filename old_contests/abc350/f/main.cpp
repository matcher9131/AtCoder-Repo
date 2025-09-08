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

char trans(char c) {
    if ('a' <= c && c <= 'z') {
        return c - 32;
    } else {
        return c + 32;
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> paren(n, -1);
    vector<int> l;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            l.push_back(i);
        } else if (s[i] == ')') {
            int j = l.back();
            l.pop_back();
            paren[i] = j;
            paren[j] = i;
        }
    }

    function<void(int,int,bool)> dfs = [&](int l, int r, bool odd) {
        if (odd){
            for (int i = r; i >= l; --i) {
                if (s[i] == ')') {
                    int j = paren[i];
                    dfs(j+1, i-1, false);
                    i = j;
                } else if (s[i] != '(') {
                    cout << trans(s[i]);
                }
            }
        } else {
            for (int i = l; i <= r; ++i) {
                if (s[i] == '(') {
                    int j = paren[i];
                    dfs(i+1, j-1, true);
                    i = j;
                } else if (s[i] != ')') {
                    cout << s[i];
                }
            }
        }
    };

    dfs(0, n - 1, false);
    cout << endl;
    
    return 0;
}