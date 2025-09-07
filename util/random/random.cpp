#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;

extern int seed;
extern int l;
extern int r;

mt19937 gen(seed);
uniform_int_distribution<> dist(l, r);
// ※ l <= x <= r
