# [ARC167](https://atcoder.jp/contests/arc167) Review
- Rated参加
- 前日と打って変わってレートが大幅プラス
  - 再び1300台に復帰
- 一方でC以降はまだ厳しい
  - …って今回のC, Dは黄色かい！

## A - Toasts for Breakfast Party
- AC
- 以下の方法でOK
    1. トーストを美味しさの高い順に並べる
    1. 全ての皿に1枚ずつトーストを乗せる
    1. 乗っているトーストの美味しさが低い順に皿を選んでもう1枚ずつトーストを乗せていく
- 計算量はソートがボトルネックになるため $O(N \log N)$
- 貪欲法でOKなことに確信を持つのに時間がかかってしまった
- 貪欲法でOKなことの証明
  - $0 \leq a \leq b \leq c$ に対し、$(a + b)^2 + c^2 \leq (a + c)^2 + b^2 \leq (b + c)^2 + a^2$ なので
    - トーストが1枚のみの皿と2枚の皿が両方存在する場合は1枚の皿の美味しさを最大にするべき
  - $0 \leq a \leq b \leq c \leq d$ に対し、$(a + d)^2 + (b + c)^2 \leq (a + c)^2 + (b + d)^2 \leq (a + b)^2 + (c + d)^2$ なので
    - トーストが2枚の皿どうしの場合は美味しさの大きいものと小さいものを組み合わせるべき

## B - Product of Divisors
- AC
- 以下、自然数 $n$ の正の約数の個数を $f(n)$ と表す
  - なお $f(n)$ は以下のようにして求まる
    - $n$ を素因数分解して $\displaystyle n = \prod_{i = 1}^{k} p_i^{a_i}$（ただし $p_i$ は相異なる素数、$a_i$ は自然数、 $k$ は $n$ の素因数の種類数）と表したとき、$\displaystyle f(n) = \prod_{i = 1}^{k} (a_i + 1)$
- 自然数 $n$ の正の約数を小さい順に $d_1, d_2, \dots, d_{f(n)}$ とおくと、全ての $1 \leq i \leq f(n)$ に対して $d_i d_{f(n) - i} = n$ であるから、$n$ の正の約数の総積は $n^{f(n)/2}$ となる
- よって $C = f(A^B)$ とおくと、$A^B$ の正の約数の総積は $(A^B)^{C/2} = A^{BC/2}$ なので、$A$ で $\lfloor \frac{BC}{2} \rfloor$ 回割り切れる
- 注意すべき点として、実際の計算は $\bmod 998244353$ で行っているため単純に $\lfloor \frac{BC}{2} \rfloor$ を計算することができず、$BC$ が偶数か奇数かを別途判断する必要がある
    - 一般的に自然数 $n$ に対し $f(n)$ が奇数になるのは $n$ が平方数、すなわち上述のように $n$ を素因数分解したときに $a_1, a_2, \dots, a_k$ がすべて偶数になる場合であるため、素因数分解を行う際にこれを監視すれば $C$ が奇数かどうかがわかる