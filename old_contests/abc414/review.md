# [ABC414](https://atcoder.jp/contests/abc414) Review
- Rated参加
- 時間の使い方を盛大に間違えて2400位
  - なお間違ってなくてもDまでしか解けていないので2000位くらいにしかならない模様
- Eが遠い……
- F難しすぎィ！


## D - Transmission Mission
- AC（15分）
- 結局のところ、 $1 \leq i \leq N-1$ に対し $D_i = X_{i+1} - X_i$ として、それを昇順にソートすると、 $\sum_{i=1}^{N-M} D_i$ が解になる
- 連続する数軒に対しその座標の最小値・最大値をそれぞれ $p,q$ とおくと、座標 $\frac{q-p}{2}$ に電波強度 $q-p$ の基地局を立てれば1つでカバーできる
  - よってある基地局によるカバーエリアにもう1つ基地局を加える場合、そのカバーエリア内で最も離れた2軒を境に分割すれば電波強度の和を最小にできる


## E - Count A%B=C
- 時間切れ
- $a = bq + c$ として $(b, q, c)$ をメインに考えていたが
  - $(a, b)$ を決めれば $c$ は一意に決まるのでこっちのほうが簡単
    - **一意性に敏感になるべし**
- $\sum_{i=1}^N \lfloor \frac{N}{i} \rfloor$ の $O(\sqrt{N})$ 解法

```cpp
ll sqrt_n = (ll)sqrt(n);
ll ans = 0;
for (ll i = 1; i <= sqrt_n; ++i) {
    ans += n / b;
}
for (ll k = 1; k <= n / (sqrt_n + 1); ++k) {
    ll count = n / k - n / (k + 1);
    ans += k * count;
}
```

- ポイント
  - $i \leq \sqrt{N}$ に関してはそのまま計算する
  - $i > \sqrt{N}$ のとき $\lfloor \frac{N}{i} \rfloor < \sqrt{N}$ なのでまとめて計算する
    - $k$ の上限を $\left\lfloor \frac{N}{\lfloor \sqrt{N} \rfloor + 1} \right\rfloor$ にすると重複や漏れが出ない
      - 前半の $i$ の最大値が $\lfloor \sqrt{N} \rfloor$ なので後半は $i = \lfloor \sqrt{N} \rfloor + 1$ から、すなわち $k = \left\lfloor \frac{N}{\lfloor \sqrt{N} \rfloor + 1} \right\rfloor$ でありこれが $k$ の最大値になる