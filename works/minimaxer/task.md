# Minimaxer

実行時間制限: 2sec / メモリ制限: 1024MiB

ABCのC問題相当

## 問題文

現実世界のヨーロッパが舞台のトラック運転シミュレーターゲーム「Euro Truck Simulator 2」では、連続した仕事により10,000km以下の走行距離で20,000XPを獲得すると Minimaxer という実績が解除されます。

たかし君はこれまで $N$ 個の仕事を請け負い、 $i$ 番目の仕事では $A_i \ \mathrm{km}$ を走行して $B_i$ 円を得ました。

たかし君が連続した $1$ 個以上の仕事において、総走行距離 $L \ \mathrm{km}$ 以下で $X$ 円以上を獲得したことがあるかどうかを判定してください。
より具体的には、 $1 \leq i \leq j \leq N$ を満たす整数 $(i,j)$ で、 $\sum_{k=i}^j A_k \leq L$ かつ $\sum_{k=i}^j B_k \geq X$ を満たすものが存在するかどうかを判定してください。

## 制約
- $1 \leq N \leq 2 \times 10^5$
- $1 \leq A_i \leq 10^9$
- $1 \leq B_i \leq 10^9$
- $1 \leq L \leq 10^9$
- $1 \leq X \leq 10^9$
- 入力される値は全て整数

## 入力
入力は以下の形式で標準入力から与えられる

$
\begin{aligned}
  N && L && X \\
  A_1 && B_1 \\
  A_2 && B_2 \\
  \vdots && \ \\
  A_N && B_N
\end{aligned}
$

## 出力
条件を満たす $1 \leq i \leq j \leq N$ が存在するとき`Yes`を、存在しないとき`No`を出力せよ。
