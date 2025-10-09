# Integer

## $A^B \bmod M$
- $A, M$ が互いに素
  - オイラーの定理
    - [ABC228 E - Integer Sequence Fair](https://atcoder.jp/contests/abc228/tasks/abc228_e)
- $O(\log B)$ が許される
  - 繰り返し二乗法
    - 特に $M$ が`int`の範囲内なら`atcoder/math`の`atcoder::pow_mod`

## 多数のGCD
- $A_1$ の約数に決め打ち
  - [ARC124 C - LCM of GCDs](https://atcoder.jp/contests/arc124/tasks/arc124_c)

## $A \bmod M$
- 何らかの $f$ を用いて $A \equiv f(A)$ を実現できる
  - [ARC176 B - Simple Math 4](https://atcoder.jp/contests/arc176/tasks/arc176_b)

## 桁DP
- $N$ 以下の制約がつく
  - DPの要素に「 $N$ の上から数桁に一致、$N$ の上から数桁未満」を追加
    - [ABC336 E - Digit Sum Divisible](https://atcoder.jp/contests/abc336/tasks/abc336_e)
    - [ABC117 D - XXOR](https://atcoder.jp/contests/abc117/tasks/abc117_d)

## XOR
- ほぼほぼ上位ビットから決めていく
  - 例： $10011_{(2)}$ の場合
    - $[00000_{(2)}, 10000_{(2)}), [10000_{(2)}, 10010_{(2)}), [10010_{(2)}, 10011_{(2)}), 10011_{(2)}$ に分ける
      - [ABC129 E - Sum Equals Xor](https://atcoder.jp/contests/abc129/tasks/abc129_e)

## $N \leq 10^{14}$
- 平方分割
  - [ABC161 F - Division or Subtraction](https://atcoder.jp/contests/abc161/tasks/abc161_f)
  - [ARC150 B - Make Divisible](https://atcoder.jp/contests/arc150/tasks/arc150_b) （ $A = BQ+R$ で $B \geq Q$ と $B < Q$ に分ける）
  - [ARC125 B - Squares](https://atcoder.jp/contests/arc125/tasks/arc125_b)
- 一見困難に見えても所謂トンチで因数分解ができる
  - [ABC420 G - sqrt(n²+n+X)](https://atcoder.jp/contests/abc420/tasks/abc420_g)　（両辺に4をかければ $X$ を分離して因数分解可）


## 区間の素因数分解
- エラストテネスの区間篩： $[1, N]$ を前処理 $O(N \log \log N)$ 、本処理 $O(N \log N)$ で素因数分解
  - [ARC116 C - Multiple Sequences](https://atcoder.jp/contests/arc116/tasks/arc116_c)

## $A_i$ が $A_j$ の倍数であるような $(i, j)$ の列挙
- $A_j$ を逆引きできるようにしておいて`for (int i = 0; i < n; ++i) for (int k = 1; k * a[i] <= max; ++k)`で探す（`max`は $\max A$ ） 
  - [ARC133 B - Dividing Subsequence](https://atcoder.jp/contests/arc133/tasks/arc133_b)

## 桁に注目して何かすべき問題だが、 $i$ 桁目のみ見てもうまくいかない
- 下 $1$ 桁、下 $2$ 桁、…の順で考える
　- [ARC158 C - All Pair Digit Sums](https://atcoder.jp/contests/arc158/tasks/arc158_c)
