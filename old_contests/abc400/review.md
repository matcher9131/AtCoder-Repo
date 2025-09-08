# [ABC400](https://atcoder.jp/contests/abc400) Review
- Rated参加
- Cでしょうもないミスをするも1時間足らずでEまで駆け抜ける
  - 結果600位台で最高レート更新

## C - 2^a b^2
- AC（10分+1WA）
- $a$ を固定して $b$ の範囲を二分探索で求めようとしたものの
  - 二分探索の初期値 $r$ を大きくしすぎて $2^a \cdot r^2$ がオーバーフローしてしまい`WA`
    - これでオーバーフロー何回目よ…

## D - Takahashi the Wall Breaker
- AC（14分）
- AtCoder ProblemsのRecommendationでやったやつや！
  - [ABC213 E - Stronger Takahashi](https://atcoder.jp/contests/abc213/tasks/abc213_e)の類題
- 変数名が被ってしまい気づくのに時間がかかった
  - そうでなければ5分くらいでできてたのに…

## E - Ringo's Favorite Numbers 3
- AC（25分）
- $X$ が 400 number のとき、 $Y = \sqrt{X}$ は整数かつ素因数の種類数が2となる
- よって $Y = \lfloor \sqrt{A} \rfloor, \lfloor \sqrt{A} \rfloor - 1, \dots$ の順に見ていき、素因数の種類数が2になる初めのものの2乗が求める 400 number である
  - 素因数の種類数は時間計算量 $O(\sqrt{Y})$ なので $Y \leq \sqrt{A} \leq 10^6$ と合わせて $10^9$ オーダーだが
    - 素因数分解で3種類目の素因数が見つかった瞬間にearly returnしたうえで
    - 400 number がそれなりに密である（と祈っていた）ので実際にはそこまでの計算量にはならないと踏んだ
      - 実際700msくらいで通っている
- （公式解説）あらかじめ $10^6$ 以下で素因数の種類数が2であるものをリストアップすれば単純に二分探索で求まる…こっちのほうが計算量が少なくかつ見通しが立つなぁ…
