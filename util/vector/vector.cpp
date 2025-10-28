#include <vector>
#include <cassert>
using namespace std;

// 加算
template <class T>
vector<T> operator+(const vector<T> &v1, const vector<T> &v2) {
    assert(v1.size() == v2.size());
    vector<T> res = v1;
    for (size_t i = 0; i < res.size(); ++i) {
        res[i] += v2[i];
    }
    return res;
}

// 反転
template <class T>
vector<T> operator-(const vector<T> &v) {
    vector<T> res(v.size());
    for (size_t i = 0; i < res.size(); ++i) {
        res[i] = -v[i];
    }
    return res;
}

// 減算
template <class T>
vector<T> operator-(const vector<T> &v1, const vector<T> &v2) {
    assert(v1.size() == v2.size());
    vector<T> res = v1;
    for (size_t i = 0; i < res.size(); ++i) {
        res[i] -= v2[i];
    }
    return res;
}

// 定数倍
template <class T>
vector<T> operator*(T k, const vector<T> &v) {
    vector<T> res = v;
    for (size_t i = 0; i < res.size(); ++i) {
        res[i] *= k;
    }
    return res;
}

// 定数倍（除算）
template <class T>
vector<T> operator/(const vector<T> &v, T k) {
    vector<T> res = v;
    for (size_t i = 0; i < res.size(); ++i) {
        res[i] /= k;
    }
    return res;
}

// 内積
template <class T>
vector<T> inner_product(const vector<T> &v1, const vector<T> &v2) {
    assert(v1.size() == v2.size());
    T res = 0;
    for (size_t i = 0; i < v1.size(); ++i) {
        res += v1[i] * v2[i];
    }
    return res;
}

// 平面で反時計回りに90度回転
template <class T>
vector<T> rotate90(const vector<T> &v) {
    assert(v.size() == 2);
    vector<T> res{ -v[1], v[0] };
    return res;
}

// 平面で時計回りに90度回転
template <class T>
vector<T> rotate270(const vector<T> &v) {
    assert(v.size() == 2);
    vector<T> res{ v[1], -v[0] };
    return res;
}
