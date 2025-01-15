# [ABC383](https://atcoder.jp/contests/abc383) Review
- バーチャル参加
- 水色問題をおくれ…

## D - 9 Divisors
- AC
- $N$ 以下の素数列挙：エラトステネスの篩（計算量 $O(N \log \log N)$ ）
    1. $2$ 以上 $N$ 以下のすべての整数を仮に素数とする
    2. 小さい方から順に見ていき、合成数と判定されていない整数 $p$ に対して以下を行う
        1. $p$ を素数で確定する
        1. $p$ 以外の $p$ の倍数をすべて合成数と判定する
- エラトステネスの篩自体は勿論知っていたものの計算量に関する知識がなかった
  - なおもっと高速なアルゴリズムがあるらしい：[素数列挙：Wheel Sieve](https://37zigen.com/wheel-sieve/)
- 該当する整数は必ず $p^8$ または $p^2q^2$ の形で表される
  - $N \leq 4 \times 10^{12}$ より $pq \leq 2 \times 10^6$ だが、 $p = 2$ の可能性を考えると $q \leq 10^6$ まで考える必要がある
    - だが $p,q \leq 10^6$ のみの制約で $p^2q^2$ を直接計算してしまうと64ビット整数型の範囲を超えてしまう（1敗）
    - よって $pq \leq \sqrt{N}$ の制約が先に必要となる