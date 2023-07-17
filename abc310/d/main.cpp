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
using namespace std;
using ll = long long;

int n, t;
// dis[i]のjビット目が1: iとjが相性が悪い
vector<unsigned> dis;
vector<unsigned> teams;
unsigned search(unsigned currentPlayer) {
    if (currentPlayer == n) {
        return teams.size() == t ? 1U : 0;
    }

    unsigned answer = 0;

    // 既にあるチームに追加
    for (auto&& team : teams) {
        if (!(team & dis[currentPlayer])) {
            team ^= 1U << currentPlayer;
            answer += search(currentPlayer + 1);
            team ^= 1U << currentPlayer;
        }
    }

    // 新しいチームに追加
    if (teams.size() < t) {
        teams.emplace_back(1U << currentPlayer);
        answer += search(currentPlayer + 1);
        teams.pop_back();
    }

    return answer;
}

int main() {
    int m;
    cin >> n >> t >> m;
    dis = vector<unsigned>(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        dis[a] |= (1U << b);
        dis[b] |= (1U << a);
    }

    teams.reserve(t);
    cout << search(0) << endl;

    return 0;
}