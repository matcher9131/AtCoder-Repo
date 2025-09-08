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

struct Mino {
private:
    vector<pair<int, int>> _cells;
    int _h, _w;
    void _shift() {
        int mi = min_element(_cells.begin(), _cells.end(), [](const auto &x, const auto &y){ return x.first < y.first; })->first;
        int mj = min_element(_cells.begin(), _cells.end(), [](const auto &x, const auto &y){ return x.second < y.second; })->second;
        for (auto &c : _cells) {
            c.first -= mi;
            c.second -= mj;
        }
    }
public:
    Mino(vector<pair<int, int>> cells) {
        _cells = cells;
        if (_cells.size() == 0) return;
        _shift();
        _h = 1 + max_element(_cells.begin(), _cells.end(), [](const auto &x, const auto &y){ return x.first < y.first; })->first;
        _w = 1 + max_element(_cells.begin(), _cells.end(), [](const auto &x, const auto &y){ return x.second < y.second; })->second;
    }
    Mino() : Mino(vector<pair<int, int>>()) {}

    vector<pair<int, int>>::iterator begin() { return _cells.begin(); }
    vector<pair<int, int>>::iterator end() { return _cells.end(); }

    Mino get_rotated(int dir) {
        vector<pair<int, int>> newCells = _cells;
        // 左回転：(i, j) -> (3 - j, i)
        if (dir == 1) {
            for (auto &c : newCells) {
                auto [i, j] = c;
                c = make_pair(3 - j, i);
            }
            return Mino(newCells);
        }
        // 180度回転：(i, j) -> (3 - i, 3 - j)
        if (dir == 2) {
            for (auto &c : newCells) {
                auto [i, j] = c;
                c = make_pair(3 - i, 3 - j);
            }
            return Mino(newCells);
        }
        // 右回転：(i, j) -> (j, 3 - i)
        if (dir == 3) {
            for (auto &c : newCells) {
                auto [i, j] = c;
                c = make_pair(j, 3 - i);
            }
            return Mino(newCells);
        }
        // 無回転
        return Mino(newCells);
    }

    int get_height() { return _h; }
    int get_width() { return _w; }
};

bool can_set_mino(vector<vector<bool>> &g, int i, int j, Mino &mino) {
    for (const auto &[ci, cj] : mino) {
        if (g[i + ci][j + cj]) return false;
    }
    return true;
}
void set_mino(vector<vector<bool>> &g, int i, int j, Mino &mino) {
    for (const auto &[ci, cj] : mino) {
        g[i + ci][j + cj] = true;
    }
}
void remove_mino(vector<vector<bool>> &g, int i, int j, Mino &mino) {
    for (const auto &[ci, cj] : mino) {
        g[i + ci][j + cj] = false;
    }
}
bool covered_all(vector<vector<bool>> &g) {
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            if (!g[i][j]) return false;
        }
    }
    return true;
}

int main() {
    vector<vector<Mino>> mino(3, vector<Mino>(4));
    for (int i = 0; i < 3; ++i) {
        vector<pair<int, int>> cells;
        for (int j = 0; j < 4; ++j) {
            string s;
            cin >> s;
            for (int k = 0; k < 4; ++k) {
                if (s[k] == '#') cells.emplace_back(j, k);
            }
        }
        auto m = Mino(cells);
        for (int dir = 0; dir < 4; ++dir) {
            mino[i][dir] = m.get_rotated(dir);
        }
    }

    vector<vector<bool>> g(4, vector<bool>(4));
    for (int dir0 = 0; dir0 < 4; ++dir0) {
        for (int i0 = 0; i0 <= 4 - mino[0][dir0].get_height(); ++i0) {
            for (int j0 = 0; j0 <= 4 - mino[0][dir0].get_width(); ++j0) {
                if (!can_set_mino(g, i0, j0, mino[0][dir0])) continue;
                set_mino(g, i0, j0, mino[0][dir0]);

                for (int dir1 = 0; dir1 < 4; ++dir1) {
                    for (int i1 = 0; i1 <= 4 - mino[1][dir1].get_height(); ++i1) {
                        for (int j1 = 0; j1 <= 4 - mino[1][dir1].get_width(); ++j1) {
                            if (!can_set_mino(g, i1, j1, mino[1][dir1])) continue;
                            set_mino(g, i1, j1, mino[1][dir1]);

                            for (int dir2 = 0; dir2 < 4; ++dir2) {
                                for (int i2 = 0; i2 <= 4 - mino[2][dir2].get_height(); ++i2) {
                                    for (int j2 = 0; j2 <= 4 - mino[2][dir2].get_width(); ++j2) {
                                        if (!can_set_mino(g, i2, j2, mino[2][dir2])) continue;
                                        set_mino(g, i2, j2, mino[2][dir2]);
                                        if (covered_all(g)) {
                                            cout << "Yes" << endl;
                                            return 0;
                                        }
                                        remove_mino(g, i2, j2, mino[2][dir2]);
                                    }
                                }
                            }

                            remove_mino(g, i1, j1, mino[1][dir1]);
                        }
                    }
                }

                remove_mino(g, i0, j0, mino[0][dir0]);
            }
        }
    }

    cout << "No" << endl;
    return 0;
}