#include <bits/stdc++.h>
#include <atcoder/math>
using namespace std;
using ll = long long;

template <class T>
class RollingHash {
private:
    static constexpr ll B = 27;
    static constexpr ll MOD1 = 998244353;
    static constexpr ll MOD2 = 1000000007;
    initializer_list<T> _list;
    size_t _whole_size;
    size_t _size;
    size_t _valid = 0;
    vector<ll> _hash1, _hash2;

public:
    RollingHash(initializer_list<T> list, size_t size) : _list(list), _whole_size(list.size()), _size(size) {
        _hash1.resize(list.size(), 0);
        _hash2.resize(list.size(), 0);
        for (size_t i = 0; i < _size; ++i) {
            _hash1[0] = (_hash1[0] * B + _list[i]) % MOD1;
            _hash2[0] = (_hash2[0] * B + _list[i]) % MOD2;
        }
    }

    pair<ll, ll> get_hash(size_t start) {
        assert(start < _whole_size);
        for (size_t i = _valid; i < start; ++i) {
            _hash1[i+1] -= _list[i] * atcoder::pow_mod(B, _size-1, MOD1);
            _hash1[i+1] *= B;
            _hash1[i+1] += _list[(i+_size) % _whole_size];
            _hash1[i+1] %= MOD1;
            if (_hash1[i+1] < 0) _hash1[i+1] += MOD1;
            
            _hash2[i+1] -= _list[i] * atcoder::pow_mod(B, _size-1, MOD2);
            _hash2[i+1] *= B;
            _hash2[i+1] += _list[(i+_size) % _whole_size];
            _hash2[i+1] %= MOD2;
            if (_hash2[i+1] < 0) _hash2[i+1] += MOD2;
        }
        return { _hash1[start], _hash2[start] };
    }
};
