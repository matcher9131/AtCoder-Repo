# [あさかつ9/24](https://kenkoooo.com/atcoder/#/contest/show/2afc4e4c-8ea1-411c-8e7f-074f382c158b) Review

## 第4問 - Flip Edge
- AC（7分）
- いわゆる頂点倍加
- 元のグラフ $G$ の有向辺の向きをすべて逆にしたグラフを $G'$ とし、 $G'$ の頂点 $i$ が $G$ の頂点 $N+i$ になるように辺を含めてマージする
  - 辺のコストはすべて $1$ とする
- さらに $G$ に頂点 $i$ と $N+i$ を双方向に結ぶコスト $X$ の辺を追加する
- この状態でDijkstraすればOK

## 第5問 - Subsegments with Small Sums
- 時間切れ
- 以降 $f((A_l, A_{l+1}, \dots, A_{r}))$ を $f(l, r)$ と書くことにする
- $\sum_{k=i}^j A_k > S$ となる最小の $j$ を $B_i$ とすると（ $j$ が存在しない場合は $B_i = N+1$ とする）
  - $i \leq j < B_i$ に対し $f(i, j) = 1$ 、 $j \geq B_i$ に対し $f(i, j) = 1 + f(B_i, j)$ がわかる
  - $B_i$ は尺取法で $O(N)$ で計算できる
- $\mathrm{dp}_{i} = \sum_{k=i}^N f(i, k)$ とおくと

$$
\begin{align*}
    \mathrm{dp}_{i} &= f(i, i) + f(i, i+1) + \dots + f(i, B_i-1) + f(i, B_i) + f(i, B_i + 1) \\
    &= N - i + 1 + f(B_i, B_i) + f(B_i , B_i + 1) + \dots + f(B_i, N) \\
    &= N - i + 1 + \mathrm{dp}_{B_i}
\end{align*}
$$

- よって後ろからDPを求めていくことで解が求まる

## 第6問 - Operations on a Matrix
- 時間切れ
- クエリ2で $x$ に置き換える前の列和 $S_j$ を記憶しておけば、クエリ3時点での列和 $S'_j$ を用いて累積和の要領で $S'_j - S_j + x$ と解が求められる
  - ただしクエリ2のたびに全列の列ごとの和 $S_j$ を記憶しようとするのは勿論`TLE`
- クエリ3が高々 $Q$ 個しかないので記憶すべきものも高々 $Q$ 個しかないのがポイント
  - よってあらかじめそれぞれのクエリ3 $(i,j)$ に対して直近の第 $i$ 行に対するクエリ2を探し、どの $S_j$ を記憶すべきなのかを把握しておくとうまくいく  
