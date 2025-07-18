#include <limits>
#include <queue>
#include <functional>

template <typename T>
struct SlopeTrick {
    const T INF = numeric_limits<T>::max() / 3;
    
    T min_f;
    priority_queue<T, vector<T>, less<>> l;
    priority_queue<T, vector<T>, greater<>> r;
    T add_l, add_r;

private:
    void push_r(const T &a) {
        r.push(a - add_r);
    }

    T top_r() const {
        if (r.empty()) return INF;
        else return r.top() + add_r;
    }

    T pop_r() {
        T val = top_r();
        if (!r.empty()) r.pop();
        return val;
    }

    void push_l(const T &a) {
        l.push(a - add_l);
    }

    T top_l() const {
        if (l.empty()) return -INF;
        else return l.top() + add_l;
    }

    T pop_l() {
        T val = top_l();
        if (!l.empty()) l.pop();
        return val;
    }

    size_t size() {
        return l.size() + r.size();
    }

public:
    SlopeTrick(): min_f(0), add_l(0), add_r(0) {}

    T get_min_f() const {
        return min_f;
    }

    pair<T, T> get_min_segment() const {
        return { top_l(), top_r() };
    }

    void add_all(const T &a) {
        min_f += a;
    }

    // f(x) += max(a-x, 0)
    void add_upper_left(const T &a) {
        min_f += max(T(0), a - top_r());
        push_r(a);
        push_l(pop_r());
    }

    // f(x) += max(0, x-a)
    void add_upper_right(const T &a) {
        min_f += max(T(0), top_l() - a);
        push_l(a);
        push_r(pop_l());
    }

    void clear_right() {
        while (!r.empty()) r.pop();
    }

    void clear_left() {
        while (!l.empty()) l.pop();
    }

    // 左側を+a、右側を+b平行移動
    void shift(const T &a, const T &b) {
        assert(a <= b);
        add_l += a;
        add_r += b;
    }

    void merge(SlopeTrick &other) {
        if (other.size() > size()) {
            swap(other.min_f, min_f);
            swap(other.l, l);
            swap(other.r, r);
            swap(other.add_l, add_l);
            swap(other.add_r, add_r);
        }
        while (!other.r.empty()) add_upper_right(other.pop_r());
        while (!other.l.empty()) add_upper_left(other.pop_l());
        min_f += other.min_f;
    }
};