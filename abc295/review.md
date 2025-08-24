# [ABC295] Review
- バーチャル参加
- Eまでを45分で290位相当
  - 今だと多分700位くらいなんだろうなぁ……

## D - Three Days Ago
- AC（9分）
- 以下のように集合列 $A_0, A_1, \dots, A_N$ を定める
  - $A_0 = \emptyset$
  - $A_{i} = A_{i-1} \cup \{ S_i \} (S_i \notin A_{i-1}), \ A_{i-1} \setminus \{ S_i \} (S_i \in A_{i-1})$
- このとき $S[l,r]$ が嬉しい列である必要十分条件は $A_{l-1} = A_{r}$ なので、これを満たす $(l,r)$ を数え上げればよい
  - $A$ の要素数は高々 $10$ 個なのでビット集合で管理できる
- 計算量は $N$ を1桁の数の種類数として $O(|S| + 2^N)$

## E - Kth Number
- AC（23分＋1RE）
- $A$ のうち $K$ 項以上が $x$ 以下になる確率を $P_x$ とおくと、 $A_K = x$ となる確率は $P_x - P_{x-1}$ と表せ、解は $\sum_{x=1}^M x(P_x - P_{x-1})$ となる
- 元の $A$ において $A_i = x$ となる $i$ の個数を $C_x$ とおくと、
  - $\sum_{y=0}^x C_y < K$ のとき、 $0$ が何に変わっても $A_K > x$ が確定するので $P_x = 0$
  - $\sum_{y=1}^x C_y \geq K$ のとき、 $0$ が何に変わっても $A_K \leq x$ が確定するので $P_x = 1$
  - それ以外のとき、 $C_0$ 個の $0$ のうち何個が $x$ 以下になるかで場合分けして考えることで ${\displaystyle P_x = \sum_{j = K - \sum_{y=1}^x C_y}^{C_0} \begin{pmatrix} C_0 \\ j \end{pmatrix} \left( \frac{x}{M} \right)^{j} \left( 1 - \frac{x}{M} \right)^{C_0 - j} }$ を得る
- 計算量は $O(NM)$
- （公式解説） $\sum P(X \leq i)$ でいいのか……！
