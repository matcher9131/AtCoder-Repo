# [ABC360](https://atcoder.jp/contests/abc361) Review
- バーチャル参加
- 1時間弱をFにつぎ込むも解けず…と思ったらお前橙色かよ！！
  - すなわちEまでのスピードが物を言う展開で、スムーズだったため700位以内相当
    - いつもこれくらいならいいんですがねぇ……

## D - Ghost Ants
- AC
- 全ての蟻の移動する距離が等しいため、同じ向きを向いている蟻どうしがすれ違うことはない
  - 正方向を向いている蟻 $i$ と負方向を向いている蟻 $j$ がすれ違う条件は、 $X_i < X_j$ かつ $X_i + T \geq X_j - T$ すなわち $X_i < X_j \leq X_i + 2T$
- よって負方向を向いている蟻を初期座標でソートして、全ての正方向を向いている蟻 $i$ に対して二分探索で↑を満たす蟻 $j$ をカウントすればOK
  - 時間計算量は $O(N \log N)$

## E - Random Swaps of Balls
- AC(2RE、うち1回WA含む)
- 以下 $n \geq 2$ とする
- $i$ 回操作後に黒いボールが左から $x$ 番目にある確率を $P(i, x)$ とおくと、対称性より任意の $i$ に対し $P(i, 2) = P(i, 3) = \dots = P(i, N)$ が成り立つ
  - よって $x \geq 2$ に対し $P(i, x) = \dfrac{1 - P(i, 1)}{N-1}$ である
- 状態遷移も $x = 1$ かそれ以外かの2つで管理すればOK
  - $i$ 回操作後に $x = 1$ の場合において、次の操作で $x = 1$ のままとなるのは「 $a \neq 1$ かつ $b \neq 1$ 」または $a = b = 1$ のいずれかなので、その条件付き確率は $\dfrac{(N-1)^2 + 1}{N^2}$
  - $i$ 回操作後に $x \neq 1$ の場合において、次の操作で $x = 1$ となるのは $(a, b) = (1, x), (x, 1)$ のときなので、その条件付き確率は $\dfrac{2}{N^2}$
- あとは $P(K, x)$ を用いて期待値を計算するのみ
  - 上述の対称性より $E(x) = \sum_{x=1}^N xP(K, x) = P(K, 1) + \sum_{x=2}^N x\dfrac{1 - P(K, 1)}{N-1} = P(K, 1) + \left( \dfrac{N(N+1)}{2} - 1 \right)\dfrac{1 - P(K, 1)}{N-1}$ となる
- なお $N=1$ を弾き忘れて除算エラー1回、 $N(N+1)$ を`int`のまま計算してしまい`WA`1回を食らう
  - 10分早ければもっと上位を狙えていた……

## F - InterSections
- 時間切れ
- （公式解説）区間 $[l, r]$ を $lr$ 座標平面に置いて考えるテクは知らなかったので今後使えるようにしたい
