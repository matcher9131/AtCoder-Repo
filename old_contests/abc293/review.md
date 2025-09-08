# [ABC293](https://atcoder.jp/contests/abc293) Review
- バーチャル参加
- 96分でFまで解いて550位相当

## D - Tying Rope
- AC（20分）
- ちょっと変わったDFS
- ロープ $i$ の赤端を頂点 $2i-1$, 青端を頂点 $2i$ として、頂点 $k$ に繋がっている頂点を $A_k$ （ない場合は $-1$ ）としておく
- $A_k = -1$ となっている頂点を見つけて順次DFS
  - これらは環状になっていないロープとしてカウントする
- ↑で訪れていない頂点を見つけて順次DFS
  - これらは環状になっているロープとしてカウントする
- 計算量は $O(N+M)$

## E - Geometric Progression
- AC（21分）
- 漸化式を行列に見立てて行列累乗で解決するパティーン
- $B_k = \sum_{i=0}^{k-1} A^i$ とおくと、 $B_k = AB_{k-1} + 1$
- これを $\begin{pmatrix} B_k \\ 1 \end{pmatrix} = \begin{pmatrix} A & 1 \\ 0 & 1 \end{pmatrix} \begin{pmatrix} B_{k-1} \\ 1 \end{pmatrix} = \begin{pmatrix} A & 1 \\ 0 & 1 \end{pmatrix}^{K-1}\begin{pmatrix} B_1 \\ 1 \end{pmatrix}$ と見れば行列階乗で求められる

## F - Zero or One
- AC（40分）
- $b=2$ は無条件で解になる
- $N$ が $b$ 進数で $d$ 桁で表せるとすると、 $b^{d-1} \leq N$ すなわち $b \leq N^{\frac{1}{d-1}}$ を満たす
  - $3^{38} > 10^{18}$ より $d \leq 38$
  - $d \geq 4$ のとき $N^{\frac{1}{d-1}} \leq 10^6$ より $d$ を固定して全探索可能
  - $d = 3$ のとき
    - $N = b^2, b^2+b, b^2+1, b^2+b+1$ のいずれかで表せるとき $b$ が解になる
      - これら4つの2次方程式を直接解くことで確認できる
  - $d = 2$ のとき
    - $N = b, b+1$ すなわち $b = N-1, N$ が（ $b>1$ なら）解になる
  - $N \geq 2$ より $d = 1$ は不可
- 解の管理に`unordered_set`を使うことで重複を気にせず数えられる
- 計算量は多少雑に見積もって $O(N^{\frac{1}{3}}\log N)$
